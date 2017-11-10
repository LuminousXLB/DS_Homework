#pragma once
#include "linkQueue.h"
#include <stack>
#include <deque>

using namespace std;

template <class elemType>
class tree {
private:
    class Node;

    Node *root;
public:
    tree(): root(NULL) {}

    tree(const elemType& value) {
        root = new Node(value);
    }
    tree(const Node *p) {
        root = p;
    }
    ~tree() {
        clear();
    }
    void clear() {
        if (root != NULL) {
            clear(root);
        }
        root = NULL;
    }
    void preOrder() const;

    void postOrder() const;

    void HierarchicalTraversal() const;
    void createTree(elemType flag);

private:
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
};


template <class elemType>
class tree<elemType>::Node {
public:
    Node *left, *right;
    elemType data;
    bool printed;
    Node(): left(NULL), right(NULL), printed(false) {}
    Node(elemType item, Node * L = NULL, Node * R = NULL): data(item), left(L), right(R), printed(false) {}
};


template <class elemType>
void tree<elemType>::createTree(elemType flag) {
    linkQueue<Node *> que;
    Node *tmp;
    elemType x;

    cout << "\nEnter the root node: ";

    cin >> x;

    root = new Node(x);
    que.enQueue(root);
    while (!que.isEmpty()) {
        tmp = que.deQueue();
        cout << "\nEnter the children of " << tmp->data << ", (" << x << " to Stop): ";
        cin >> x;
        if (x != flag) {
            que.enQueue(tmp->left = new Node(x));
            tmp = tmp->left;

            cin >> x;
            while (x != flag) {
                que.enQueue(tmp->right = new Node(x));
                tmp = tmp->right;
                cin >> x;
            }
        }
    }
}


template <class elemType>
void tree<elemType>::preOrder() const {
    stack<Node *> repo, trans;

    repo.push(root);
    cout << "\npreOrder\t";

    while (!repo.empty()) {
        Node *tmp = repo.top();
        repo.pop();
        cout << tmp->data << ' ';
        if (tmp->left) {
            trans.push(tmp = tmp->left);
            while (tmp->right) {
                trans.push(tmp = tmp->right);
            }
            while (!trans.empty()) {
                repo.push(trans.top());
                trans.pop();
            }
        }
    }
}


template <class elemType>
void tree<elemType>::postOrder() const {
    stack<Node *> repo;

    repo.push(root);
    bool base = root->printed;
    cout << "\npostOrder\t";

    while (!repo.empty()) {
        Node *tmp = repo.top();
        if (tmp->left && (tmp->left->printed == base)) {
            repo.push(tmp->left);
        } else {
            cout << tmp->data << ' ';
            tmp->printed = !base;
            repo.pop();
            if (tmp->right && (tmp->right->printed == base)) {
                repo.push(tmp->right);
            }
        }
    }
}


template <class elemType>
void tree<elemType>::HierarchicalTraversal() const {
    deque<Node *> repo;

    repo.push_back(root);
    bool base = root->printed;
    cout << "\nHierarchicalTraversal\t";

    while (!repo.empty()) {
        Node *tmp = repo.front();
        cout << tmp->data << ' ';
        repo.pop_front();

        if (tmp->right) {
            repo.push_front(tmp->right);
        }
        if (tmp->left) {
            repo.push_back(tmp->left);
        }
    }
}
