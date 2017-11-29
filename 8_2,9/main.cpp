#include <iostream>
#include "BinarysearchTree.h"

using namespace std;

//用于演示的函数
template <class T>
void removeLessThan(BinarySearchTree<T> tree, T x) {
    cout << "==== REMOVE LESS THAN ====" << endl;
    tree.print();
    tree.removeLessThan(x);
    cout << "aftre remove elements less than " << x << "," << endl;
    tree.print();
    cout << endl;
}


int main() {
    int a[] = { 10, 8, 6, 21, 87, 56, 4, 0, 11, 3, 22, 7, 5, 34, 1, 2, 9 };

    BinarySearchTree<int> tree;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }

    cout << "the 1st max is " << tree.findIthMax(1) << endl;
    cout << "the " << 6 << "th max is " << tree.findIthMax(6) << endl;
    cout << "the " << 17 << "th max is " << tree.findIthMax(17) << endl;
    cout << endl;

    tree.print();
    tree.removeLessThan(4);
    cout << "aftre remove elements less than " << 4 << "," << endl;
    tree.print();
    cout << endl;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }
    tree.print();
    tree.removeLessThan(12);
    cout << "aftre remove elements less than " << 12 << "," << endl;
    tree.print();
    cout << endl;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }
    tree.print();
    tree.removeLessThan(23);
    cout << "aftre remove elements less than " << 23 << "," << endl;
    tree.print();
    cout << endl;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }
    tree.print();
    tree.removeLargeThan(22);
    cout << "aftre remove elements large than " << 22 << "," << endl;
    tree.print();
    cout << endl;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }
    tree.print();
    tree.removeLargeThan(7);
    cout << "aftre remove elements large than " << 7 << "," << endl;
    tree.print();
    cout << endl;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }
    tree.print();
    tree.removeBetween(7, 9);
    cout << "aftre remove elements between 7,9" << endl;
    tree.print();
    cout << endl;

    for (int i = 0; i < 17; ++i) {
        tree.insert(a[i]);
    }
    tree.print();
    tree.removeBetween(7, 23);
    cout << "aftre remove elements between 7,23 (23 is not in the tree)" << endl;
    tree.print();
    cout << endl;

    return 0;
}
