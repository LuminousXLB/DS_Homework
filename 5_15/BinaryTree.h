#pragma once
#include <queue>
#include <vector>
using namespace std;

class InvalidElement {};

template <class elemType>
class BinaryTree {
 private:
  vector<elemType *> store_;
  static void defaultfunc(const elemType &elem) {
    // 默认函数
    cout << elem << '\t';
  }

 public:
  BinaryTree() : store_(1, nullptr) {
    // 构造空二叉树
  }
  BinaryTree(const elemType &rootdata) : store_(2, nullptr) {
    // 从根节点数据建立一个树
    assign(1, rootdata);
  }
  BinaryTree(const BinaryTree &bt) {
    // 拷贝构造函数
    store_.reserve(bt.store_.size());
    for (size_t i = 1; i < bt.store_.size(); ++i) {
      if (bt.store_[i]) {
        assign(i, *bt.store_[i]);
      }
    }
  }
  ~BinaryTree() {
    // 析构二叉树
    clear();
  }

  void clear();                                  // 清空
  bool isEmpty() const;                          // 判空
  elemType *root() const;                        // 找根结点
  elemType *parent(const elemType &elem) const;  // 找父结点
  elemType *lchild(const elemType &elem) const;  // 找左儿子
  elemType *rchild(const elemType &elem) const;  // 找右儿子
  bool delLeft(const elemType &elem);            // 删除左子树
  bool delRight(const elemType &elem);           // 删除右子树
  void MakeTree(elemType rootelem, BinaryTree &tl,
                BinaryTree &tr);  // 构建一棵树
  void preOrderTraverse(void (*f)(const elemType &) = defaultfunc);  // 前序遍历
  void midOrderTraverse(void (*f)(const elemType &) = defaultfunc);  // 中序遍历
  void postOrderTraverse(
      void (*f)(const elemType &) = defaultfunc);  // 后序遍历
  void hierarchicalTraverse(
      void (*f)(const elemType &) = defaultfunc);  // 层级遍历
  void createTree(const elemType &flag);

 private:
  void assign(size_t index, const elemType &data) {
    // private: 单个赋值
    if (index >= store_.size()) {
      // 若index超过size的范围，则需resize
      size_t newsize = index + 1;
      if (newsize > store_.capacity()) {
        // 若resize会触发重新分配，则使capacity倍增，减少重新分配的次数
        size_t newcapacity = newsize * 2;
        while (newsize > newcapacity) {
          newcapacity *= 2;
        }
        store_.reserve(newcapacity);
      }
      // 调用resize增大长度并使用空指针初始化
      store_.resize(newsize, nullptr);
    }
    if (store_[index]) {
      // index处原非空
      if (*store_[index] == data) {
        return;
      } else {
        delete store_[index];
      }
    }
    // 设定新值
    store_[index] = new elemType(data);
  }
  bool remove(size_t index) {
    // private: 单个删除
    if ((index < store_.size()) && store_[index]) {
      // index处原非空，析构，清空指针
      delete store_[index];
      store_[index] = nullptr;

      return true;
    } else {
      // index处原为空
      return false;
    }
  }
  size_t find(const elemType &elem) {
    // 查找elem的位置
    size_t index = 0;
    for (size_t i = 1; i < store_.size(); i++) {
      if (store_[i]) {
        // 遍历非空元素
        if (elem == *store_[i]) {
          if (&elem == store_[i]) {
            return i;
          }
          index = i;
        }
      }
    }
    return index;
  }
  bool removeSubtree(size_t index) {
    if (remove(index)) {
      removeSubtree(index * 2);
      removeSubtree(index * 2 + 1);
      return true;
    } else {
      return false;
    }
  }
  void preOrder(size_t index, void (*f)(const elemType &elem)) {
    if (index < store_.size() && store_[index]) {
      f(*store_[index]);
      preOrder(index * 2, f);
      preOrder(index * 2 + 1, f);
    }
  }
  void midOrder(size_t index, void (*f)(const elemType &elem)) {
    if (index < store_.size() && store_[index]) {
      midOrder(index * 2, f);
      f(*store_[index]);
      midOrder(index * 2 + 1, f);
    }
  }
  void postOrder(size_t index, void (*f)(const elemType &elem)) {
    if (index < store_.size() && store_[index]) {
      postOrder(index * 2, f);
      postOrder(index * 2 + 1, f);
      f(*store_[index]);
    }
  }
};

template <class elemType>
void BinaryTree<elemType>::clear() {
  // 清空树
  for (size_t i = 0; i < store_.size(); i++) {
    remove(i);
  }
  store_.resize(1, nullptr);
}

template <class elemType>
bool BinaryTree<elemType>::isEmpty() const {
  return !(store_.size() > 1 && store_[1]);
}

template <class elemType>
elemType *BinaryTree<elemType>::root() const {
  // 找出二叉树的根结点。如果树是空树，则返回nullptr
  if (!isEmpty()) {
    return store_[1];
  } else {
    return nullptr;
  }
}

template <class elemType>
elemType *BinaryTree<elemType>::parent(const elemType &elem) const {
  // 找出结点x的父结点，若为根节点则返回nullptr
  size_t index = find(elem);
  if (index) {
    if (index == 1) {
      return nullptr;
    } else if (index > 1) {
      return store_[index / 2];
    }
  } else {
    throw InvalidElement();
  }
}

template <class elemType>
elemType *BinaryTree<elemType>::lchild(const elemType &elem) const {
  // 找出结点x的左儿子节点，若无左儿子则返回nullptr
  size_t index = find(elem);
  if (index) {
    if (2 * index >= store_.size()) {
      return nullptr;
    } else {
      return store_[2 * index];
    }
  } else {
    throw InvalidElement();
  }
}

template <class elemType>
elemType *BinaryTree<elemType>::rchild(const elemType &elem) const {
  // 找出结点x的右儿子节点，若无右儿子则返回nullptr
  size_t index = find(elem);
  if (index) {
    if (2 * index + 1 >= store_.size()) {
      return nullptr;
    } else {
      return store_[2 * index + 1];
    }
  } else {
    throw InvalidElement();
  }
}

template <class elemType>
bool BinaryTree<elemType>::delLeft(const elemType &elem) {
  // 删除左子树
  size_t index = find(elem);
  store_.shrink_to_fit();
  return removeSubtree(2 * index);
}

template <class elemType>
bool BinaryTree<elemType>::delRight(const elemType &elem) {
  // 删除右子树
  size_t index = find(elem);
  store_.shrink_to_fit();
  return removeSubtree(2 * index + 1);
}

template <class elemType>
void BinaryTree<elemType>::MakeTree(elemType rootelem, BinaryTree &tl,
                                    BinaryTree &tr) {
  // 合并树
  size_t i = 1, index, ls = tl.size(), rs = tr.size();
  queue<size_t> lque, rque;

  store_.reserve(ls + rs);  // 扩容
  assign(1, rootelem);      // 根结点

  // 构造左子树
  lque.push(2);
  i = 1;
  while (i < ls) {
    index = lque.front();
    assign(index, *tl.store_[i]);
    lque.push(index * 2);
    lque.push(index * 2 + 1);
    lque.pop();
    ++i;
  }

  // 构造右子树
  rque.push(3);
  i = 1;
  while (i < rs) {
    index = rque.front();
    assign(index, *tr.store_[i]);
    rque.push(index * 2);
    rque.push(index * 2 + 1);
    rque.pop();
    ++i;
  }
  store_.shrink_to_fit();
}

template <class elemType>
void BinaryTree<elemType>::preOrderTraverse(void (*f)(const elemType &)) {
  // 前序遍历
  preOrder(1, f);
}

template <class elemType>
void BinaryTree<elemType>::midOrderTraverse(void (*f)(const elemType &)) {
  // 中序遍历
  midOrder(1, f);
}

template <class elemType>
void BinaryTree<elemType>::postOrderTraverse(void (*f)(const elemType &)) {
  // 后序遍历
  postOrder(1, f);
}

template <class elemType>
void BinaryTree<elemType>::hierarchicalTraverse(void (*f)(const elemType &)) {
  // 层级遍历
  for (size_t i = 1; i < store_.size(); i++) {
    if (store_[i]) {
      (*f)(*store_[i]);
    }
  }
}

template <class elemType>
void BinaryTree<elemType>::createTree(const elemType &flag) {
  queue<size_t> que;

  elemType x, ldata, rdata;
  cout << "\nEnter the root node: ";
  cin >> x;

  assign(1, x);
  que.push(1);

  while (!que.empty()) {
    size_t i = que.front();
    cout << "\nEnter the 2 sons' of " << *store_[1] << ", (" << flag
         << " as NULL): ";
    cin >> ldata >> rdata;
    if (ldata != flag) {
      que.push(i * 2);
      assign(i * 2, ldata);
    }
    if (rdata != flag) {
      que.push(i * 2 + 1);
      assign(i * 2 + 1, rdata);
    }
    que.pop();
  }
  cout << "create completed!\n";
}
