#pragma once
#include <stack>

using namespace std;

template <class Type>
class BinarySearchTree {
 private:
  struct BinaryNode  // 二叉树结点结构
  {
    Type data;          // 节点键值
    BinaryNode *left;   // 指向左孩子的指针
    BinaryNode *right;  // 指向右孩子的指针
    BinaryNode(const Type &thedata, BinaryNode *lt, BinaryNode *rt)
        : data(thedata), left(lt), right(rt) {}
  };
  BinaryNode *root;

 public:
  BinarySearchTree(BinaryNode *t = NULL) {
    // 构造树
    root = t;
  }
  ~BinarySearchTree() {
    // 非递归析构树（栈实现）
    stack<BinaryNode *> pool;
    pool.push(root);
    root = NULL;
    while (!pool.empty()) {
      BinaryNode *tmp = pool.top();
      pool.pop();
      if (tmp->left) pool.push(tmp->left);
      if (tmp->right) pool.push(tmp->right);
      delete tmp;
    }
  }
  bool find(const Type &x) const {
    BinaryNode *t = root;
    while (t) {
      if (x < t->data) {
        t = t->left;  // x在t左侧，查找左子树
      } else if (x > t->data) {
        t = t->right;  // x在t右侧，查找右子树
      } else {
        return true;  // 查找指针的值等于x，返回找到
      }
    }
    return false;  // 查找指针为空，返回未找到
  }
  void insert(const Type &x) {
    if (root) {
      BinaryNode *t = root;
      while (t) {
        if (x < t->data) {
          // x在t左侧，在其左子树插入
          if (t->left) {
            t = t->left;
          } else {
            // 查找指针为空，新建节点，插入到t->left位置
            t->left = new BinaryNode(x, NULL, NULL);
            return;
          }
        } else if (x > t->data) {
          // x在t右侧，在其右子树插入
          if (t->right) {
            t = t->right;
          } else {
            // 查找指针为空，新建节点，插入到t->right位置
            t->right = new BinaryNode(x, NULL, NULL);
            return;
          }
        } else {
          return;  // 指针的值等于x，不必插入
        }
      }
    } else {
      root = new BinaryNode(x, NULL, NULL);
      return;
    }
  }
  void remove(const Type &x) {
    stack<BinaryNode *> history;
    BinaryNode *t = root;
    history.push(root); // 用这个东西记录筛查历史，以便于删除元素时定位父节点
    while (t) {
      if (x < t->data) {
        history.push(t->left);  // x在t左侧，在其左子树删除
      } else if (x > t->data) {
        history.push(t->right);  // x在t右侧，在其右子树删除
      } else {
        // 指针的值等于x
        if (t->left != NULL && t->right != NULL) {
          // t有两个儿子，把最小的右孙子拿上来当父亲
          // 找到最小的右儿子
          BinaryNode *tmp = t->right;  // tmp指向t的右子树
          history.push(t->right);
          while (tmp) {
            history.push(tmp->left);
            tmp = history.top();  // 右子树最小节点
          }
          history.pop(); // 把栈顶的NULL丢掉
          tmp = history.top();
          t->data = tmp->data;  // 把右子树最小节点复制到t节点
          // 删除t右子树的最小节点
          BinaryNode *oldNode = tmp;
          tmp = tmp->right;
          delete oldNode;
          history.pop(); // 把栈顶的最小右孙子丢掉，让他爹露出来
          history.top()->left = tmp;
        } else {
          // 处理t只有一个儿子的情况，直接把剩的那个儿子拽上来就好了
          BinaryNode *oldNode = t;
          t = (t->left != NULL) ? t->left : t->right;
          delete oldNode;
          history.pop();  // 把栈顶的NULL丢掉
          BinaryNode *parent = history.top();
          if (x > parent->data) {
            parent->right = t;
          } else {
            parent->left = t;
          }
        }
        break;
      }
      t = history.top();
    }

    // 指针为空，返回，没有找到x
    cout << "delete " << x << " complete" << endl;
  }
};
