#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char const *argv[]) {
    // freopen("incomplete.in", "r", stdin);
    freopen("complete.in", "r", stdin);

    BinaryTree<int> bt;

    bt.createTree(0);

    bt.preOrder();
    bt.postOrder();
    bt.midOrder();

    cout << endl;
    if (bt.isComplete()) {
        cout << "\nit's complete" << endl;
    } else {
        cout << "\nit's incomplete" << endl;
    }

    return 0;
}
