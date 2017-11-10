#pragma once
#include "BinaryTree.h"

template <class elemType>
class tree: protected BinaryTree<elemType> {
private:
public:
    void preOrder() const {}
    void postOrder() const {}
    void midOrder() const {}
    void HierarchicalTraversal() const {}
    void createTree(elemType flag);
}

template <class elemType>
void tree::createTree(elemType flag) {
    Node *tmp;
    Type x, ldata, rdata;

    cout << "\nEnter the root node: ";
    cin >> x;
    root = new Node(x);
    cout << "\nEnter the children of the root node, (" << flag << " as NULL):";
    while (cin >> x) {}
}


// template <class Type>
// void BinaryTree<Type>::createTree(Type flag) {
//     linkQueue<Node *> que;
//     Node *tmp;
//     Type x, ldata, rdata;
//     cout << "\nEnter the root node: ";
//     cin >> x;
//     root = new Node(x);
//     que.enQueue(root);
//     while (!que.isEmpty()) {
//         tmp = que.deQueue();
//         cout << "\nEnter the 2 sons' of " << tmp->data << ", (" << flag << " as NULL): ";
//         cin >> ldata >> rdata;
//         if (ldata != flag) {
//             que.enQueue(tmp->left = new Node(ldata));
//         }
//         if (rdata != flag) {
//             que.enQueue(tmp->right = new Node(rdata));
//         }
//     }
//     cout << "create completed!\n";
// }
