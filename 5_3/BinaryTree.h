// 5-1
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
            cout << "\n前序遍历：";
            preOrder(root);
        }
    }
    void postOrder() const {
        if (root != NULL) {
            cout << "\n后序遍历：";
            postOrder(root);
        }
    }
    void midOrder() const {
        if (root != NULL) {
            cout << "\n中序遍历：";
            midOrder(root);
        }
    }
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
    //创建树，输入flag表示空，ldata和rdate分别保存输入的左右孩子值
    cout << "\n输入根结点: ";
    cin >> x;
    root = new Node(x);                  //创建根节点
    que.enQueue(root);                   //根节点入队
    while (!que.isEmpty()) {
        tmp = que.deQueue();             //tmp指向出队节点，为新节点的父亲
        cout << "\n输入" << tmp->data << "的两个儿子(" << flag << "表示空结点): ";
        cin >> ldata >> rdata;                                          //外部输入的左右儿子
        if (ldata != flag) {
            //若左儿子非@, 则为出队节点创建左儿子
            que.enQueue(tmp->left = new Node(ldata));
            //入队新节点，为后续的创建做准备
        }
        if (rdata != flag) {
            //若右儿子非@, 则为出队节点创建右儿子
            que.enQueue(tmp->right = new Node(rdata));
            //新节点入队
        }
    }
    //创建过程暗含了先生成左子树后生成右子树的顺序
    cout << "create completed!\n";
    //注意此处链接指向的复杂性
}
