#pragma once
template <class Type>
class BinarySearchTree {
 private:
  struct BinaryNode  //二叉树结点结构
  {
    Type data;          //节点键值
    BinaryNode *left;   //指向左孩子的指针
    BinaryNode *right;  //指向右孩子的指针
    BinaryNode(const Type &thedata, BinaryNode *lt, BinaryNode *rt)
        : data(thedata), left(lt), right(rt) {}
  };
  BinaryNode *root;

 public:
  BinarySearchTree(BinaryNode *t = NULL) { root = t; }
  ~BinarySearchTree() { remove(root->data); }
  bool find(const Type &x) const;
  void insert(const Type &x);
  void remove(const Type &x);

 private:
  bool find(const Type &x, BinaryNode *t) const;
  void insert(const Type &x, BinaryNode *&t);
  void remove(const Type &x, BinaryNode *&t);
  // void makeEmpty(BinaryNode *&t);
};

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x) const {
  return find(x, root);
}

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x, BinaryNode *t) const {
  if (t == NULL)
    return false;  //查找指针为空，返回未找到
  else if (x < t->data)
    return find(x, t->left);  //<x，查找左子树
  else if (t->data < x)
    return find(x, t->right);  //>x，查找右子树
  else
    return true;  //查找指针的值等于x，返回找到
}

template <class Type>
void BinarySearchTree<Type>::insert(const Type &x) {
  insert(x, root);
}

template <class Type>
void BinarySearchTree<Type>::insert(const Type &x, BinaryNode *&t) {
  if (t == NULL)  //查找指针为空，新建节点，插入到t位置
    t = new BinaryNode(x, NULL, NULL);
  else if (x < t->data)
    insert(x, t->left);  //>x，在其左子树插入
  else if (t->data < x)
    insert(x, t->right);  //<x，在其右子树插入
}

template <class Type>
void BinarySearchTree<Type>::remove(const Type &x) {
  remove(x, root);
}

template <class Type>
void BinarySearchTree<Type>::remove(const Type &x, BinaryNode *&t) {
  if (t == NULL) return;  //指针为空，返回，没有找到x
  if (x < t->data)
    remove(x, t->left);  //>x，在其左子树删除
  else if (t->data < x)
    remove(x, t->right);                           //<x，在其右子树删除
  else if (t->left != NULL && t->right != NULL) {  // t有两个儿子
    BinaryNode *tmp = t->right;                    // tmp指向t的右子树
    while (tmp->left != NULL) tmp = tmp->left;     //右子树最小节点
    t->data = tmp->data;  //把右子树最小节点复制到t节点
    remove(t->data, t->right);
  }  //递归删除t右子树的最小节点
  else {
    BinaryNode *oldNode = t;  //处理t只有一个儿子的情况
    t = (t->left != NULL) ? t->left : t->right;
    delete oldNode;
  }
}
