#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char const *argv[]) {
    freopen("data.in", "r", stdin);

    BinaryTree<int> bt;

    bt.createTree(0);

    bt.preOrderTraverse();
    cout << endl;
    bt.postOrderTraverse();
    cout << endl;
    bt.midOrderTraverse();
    cout << endl;
    bt.hierarchicalTraverse();
    cout << endl;

    return 0;
}
