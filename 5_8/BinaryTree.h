// 5-1
#pragma once
#include <iostream>
#include "linkQueue.h"

using namespace std;

template <class Type>
class BinaryTree {
private:
    class Node;

    Node *root; //二叉树的根结点
public:
    BinaryTree(): root(NULL) {}  // 构造空二叉树

    BinaryTree(const Type& value) {
        root = new Node(value);
    }
    BinaryTree(const Node *p) {
        root = p;
    }
    ~BinaryTree() {
        clear();
    }
    Type getRoot() const {
        return root->data;        //返回根
    }
    Type getLeft() const {
        return root->left->data;        //返回根左孩子
    }
    Type getRight() const {
        return root->right->data;        //根右孩子
    }
    void makeTree(const Type& x, BinaryTree& lt, BinaryTree& rt) {
        // makeTree把已有的两棵树和新建立的根合并成为一棵新树
        root = new Node(x, lt.root, rt.root);
        lt.root = NULL;
        rt.root = NULL;
        //原来指向左右子树的指针设为空，避免错误 P122
    }
    void delLeft() {
        //删除左子树，调用clear()
        BinaryTree tmp = root->left;

        root->left = NULL;
        tmp.clear();
    }
    void delRight() {  //删除右子树，调用clear()
        BinaryTree tmp = root->right;

        root->right = NULL;
        tmp.clear();
    }
    bool isEmpty() const {
        return(root == NULL);
    }
    void clear() {
        if (root != NULL) {
            //调用私有函数clear()完成删除
            clear(root);
        }
        root = NULL;
    }
    int size() const {
        return(size(root));
    }
    int height() const {
        return(height(root));
    }
    void preOrder() const {
        if (root != NULL) {
            cout << "\npreOrder\t";
            preOrder(root);
        }
    }
    void postOrder() const {
        if (root != NULL) {
            cout << "\npostOrder\t";
            postOrder(root);
        }
    }
    void midOrder() const {
        if (root != NULL) {
            cout << "\nmidOrder\t";
            midOrder(root);
        }
    }
    void HierarchicalTraversal() const;
    void createTree(Type flag);

private:
    int height(Node *t) const {
        if (t == NULL) {
            return(0);
        } else {
            int lt = height(t->left), rt = height(t->right);
            return(1 + ((lt > rt) ? lt : rt));
        }
    }
    void clear(Node *t) {
        if (t->left != NULL) {
            clear(t->left);
        }
        if (t->right != NULL) {
            clear(t->right);
        }
        delete t;
        t = NULL;
    }
    int size(Node *t) const {
        if (t == NULL) {
            return(0);     //结束递归的条件
        }
        return(1 + size(t->left) + size(t->right));
    }
    void preOrder(Node *t) const {
        if (t != NULL) {                //终止递归条件
            cout << t->data << ' ';     //首先遍历根节点
            preOrder(t->left);          //然后前序遍历左子树
            preOrder(t->right);         //最后前序遍历右子树
        }
    }
    void postOrder(Node *t) const {
        if (t != NULL) {
            postOrder(t->left);         //首先后序遍历左子树
            postOrder(t->right);        //然后后序遍历左子树
            cout << t->data << ' ';     //最后遍历左子树
        }
    }
    void midOrder(Node *t) const {
        if (t != NULL) {
            midOrder(t->left);          //先中序遍历左子树
            cout << t->data << ' ';     //然后遍历左子树
            midOrder(t->right);         //最后中序遍历左子树
        }
    }
};

template <class Type>
class BinaryTree<Type>::Node {
public:
    Node *left, *right;
    Type data;
    Node(): left(NULL), right(NULL) {}
    Node(Type item, Node * L = NULL, Node * R = NULL): data(item), left(L), right(R) {}
    ~Node() {}
};

template <class Type>
void BinaryTree<Type>::createTree(Type flag) {
    linkQueue<Node *> que;
    Node *tmp;
    Type x, ldata, rdata;
    cout << "\nEnter the root node: ";
    cin >> x;
    root = new Node(x);
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << "\nEnter the 2 sons' of " << tmp->data << ", (" << flag << " as NULL): ";
        cin >> ldata >> rdata;
        if (ldata != flag) {
            que.enQueue(tmp->left = new Node(ldata));
        }
        if (rdata != flag) {
            que.enQueue(tmp->right = new Node(rdata));
        }
    }
    cout << "create completed!\n";
}


template <class Type>
void BinaryTree<Type>::HierarchicalTraversal() const {
    linkQueue<Node *> que;  // 初始化一个队列
    que.enQueue(root);      // 根节点入队
    cout << "\nHierarchicalTraversal\t";
    while (!que.isEmpty()) {
        Node *cursor = que.deQueue();   // 出队一个节点
        cout << cursor->data << ' ';    // 先输出本节点的值
        if (cursor->left) {
            que.enQueue(cursor->left);  // 再将本节点的左孩子入队
        }
        if (cursor->right) {
            que.enQueue(cursor->right); // 最后将本节点的右孩子入队
        }
    }
}
