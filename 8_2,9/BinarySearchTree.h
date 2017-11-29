#pragma once
#include <iostream>
#include <vector>

using namespace std;

class InvalidRank {};

template <class Type>
class BinarySearchTree {
 private:
  struct BinaryNode {   //二叉树结点结构
    Type data;          //节点键值
    BinaryNode *left;   //指向左孩子的指针
    BinaryNode *right;  //指向右孩子的指针
    BinaryNode(const Type &thedata, BinaryNode *lt, BinaryNode *rt)
        : data(thedata), left(lt), right(rt) {}
  };
  BinaryNode *root;

 public:
  BinarySearchTree(BinaryNode *t = NULL) { root = t; }
  ~BinarySearchTree() {
    // 非递归析构树
    makeEmpty(root);
  }
  bool find(const Type &x) const;
  const Type &findIthMax(size_t i) const {
    // 找出第i大的元素
    vector<BinaryNode *> lst = serialize();
    if (i > 0 && i <= lst.size()) {
      return lst[lst.size() - i]->data;
    } else {
      throw InvalidRank();
    }
  }
  void insert(const Type &x);
  void remove(const Type &x);
  void removeLessThan(const Type &sup);   // 删除小于sup的所有元素
  void removeLargeThan(const Type &sup);  // 删除大于inf的所有元素
  void removeBetween(const Type &inf,
                     const Type &sup);  // 删除介于inf和sup的所有元素
  void print(char sep = ' ') {
    vector<BinaryNode *> lst = serialize();
    for (size_t i = 0; i < lst.size(); ++i) {
      cout << lst[i]->data << sep;
    }
    cout << endl;
  }

 private:
  bool find(const Type &x, BinaryNode *t) const;
  void insert(const Type &x, BinaryNode *&t);
  void remove(const Type &x, BinaryNode *&t);
  void removeLessThan(const Type &sup, BinaryNode *&t);
  void removeLargeThan(const Type &inf, BinaryNode *&t);
  void removeBetween(const Type &inf, const Type &sup, BinaryNode *&t);
  void makeEmpty(BinaryNode *&t);
  vector<BinaryNode *> serialize() const {
    vector<BinaryNode *> lst;
    serialize(lst, root);
    return lst;
  }
  void serialize(vector<BinaryNode *> &lst, BinaryNode *t) const {
    if (t != NULL) {
      serialize(lst, t->left);
      lst.push_back(t);
      serialize(lst, t->right);
    }
  }
};

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x) const {
  return find(x, root);
}

template <class Type>
bool BinarySearchTree<Type>::find(const Type &x, BinaryNode *t) const {
  if (t == NULL) {
    return false;  //查找指针为空，返回未找到
  } else if (x < t->data) {
    return find(x, t->left);  //<x，查找左子树
  } else if (t->data < x) {
    return find(x, t->right);  //>x，查找右子树
  } else {
    return true;  //查找指针的值等于x，返回找到
  }
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
  if (t == NULL) {
    return;  //指针为空，返回，没有找到x
  }
  if (x < t->data) {
    remove(x, t->left);  //>x，在其左子树删除
  } else if (t->data < x) {
    remove(x, t->right);  //<x，在其右子树删除
  } else if (t->left != NULL && t->right != NULL) {  // t有两个儿子
    BinaryNode *tmp = t->right;                      // tmp指向t的右子树
    while (tmp->left != NULL) {
      tmp = tmp->left;  //右子树最小节点
    }
    t->data = tmp->data;        //把右子树最小节点复制到t节点
    remove(t->data, t->right);  //递归删除t右子树的最小节点
  } else {
    BinaryNode *oldNode = t;  //处理t只有一个儿子的情况
    t = (t->left != NULL) ? t->left : t->right;
    delete oldNode;
  }
}

template <class Type>
void BinarySearchTree<Type>::removeLessThan(const Type &sup) {
  // 删除小于sup的所有元素
  removeLessThan(sup, root);
}

template <class Type>
void BinarySearchTree<Type>::removeLessThan(const Type &sup, BinaryNode *&t) {
  if (t != NULL) {
    if (t->data < sup) {
      makeEmpty(t->left);  // 若t结点的数据小于sup，则t的左子树全部小于sup
      remove(t->data, t);  // 移除t结点，并将右子树中最小的结点移到t处
      removeLessThan(sup, t);  // 重新从t开始移除
    } else if (t->data == sup) {
      makeEmpty(t->left);  // t的左子树全部小于sup，t的右子树全部大于sup
    } else {
      // t->data > sup
      removeLessThan(sup, t->left);  // t的右子树全部大于sup，检查t的左子树
    }
  }
}

template <class Type>
void BinarySearchTree<Type>::removeLargeThan(const Type &inf) {
  // 删除小于sup的所有元素
  removeLargeThan(inf, root);
}

template <class Type>
void BinarySearchTree<Type>::removeLargeThan(const Type &inf, BinaryNode *&t) {
  if (t != NULL) {
    if (t->data > inf) {
      makeEmpty(t->right);  // 若t结点的数据大于inf，则t的右子树全部大于inf
      remove(t->data, t);  // 移除t结点的数据，已经没有右子树，故t将指向左子树
      removeLargeThan(inf, t);  // 继续检查
    } else if (t->data == inf) {
      makeEmpty(t->right);  // t的左子树全部小于inf，t的右子树全部大于inf
    } else {
      // t->data < inf
      removeLargeThan(inf, t->right);  // t的左子树全部小于inf，检查t的右子树
    }
  }
}

template <class Type>
void BinarySearchTree<Type>::removeBetween(const Type &inf, const Type &sup) {
  // 删除小于sup的所有元素
  removeBetween(inf, sup, root);
}

template <class Type>
void BinarySearchTree<Type>::removeBetween(const Type &inf, const Type &sup,
                                           BinaryNode *&t) {
  if (t != NULL) {
    if (t->data > inf && t->data < sup) {
      remove(t->data, t);          // 若t在移除的范围内，则移除t
      removeBetween(inf, sup, t);  // 移除导致t的值发生变化，重新检查t
    } else {
      removeBetween(inf, sup, t->left);   // 检查左子树
      removeBetween(inf, sup, t->right);  // 检查右子树
    }
  }
}

template <class Type>
void BinarySearchTree<Type>::makeEmpty(BinaryNode *&t) {
  if (t != NULL) {
    if (t->left) {
      makeEmpty(t->left);
    }
    if (t->right) {
      makeEmpty(t->right);
    }
    BinaryNode *oldNode = t;
    t = NULL;
    delete oldNode;
  }
}
