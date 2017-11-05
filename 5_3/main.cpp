#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char const *argv[]) {
    freopen("data.in", "r", stdin);

    BinaryTree<int> bt;

    bt.createTree(0);

    bt.preOrder();
    bt.postOrder();
    bt.midOrder();
    bt.HierarchicalTraversal();

    cout << endl;

    return 0;
}
