#include <iostream>
#include "BinarysearchTree.h"

using namespace std;

int main() {
  int a[] = {10, 8, 6, 21, 87, 56, 4, 0, 11, 3, 22, 7, 5, 34, 1, 2, 9};
  BinarySearchTree<int> tree;

  for (int i = 0; i < 17; ++i) {
    tree.insert(a[i]);
  }

  tree.midOrder();
  cout << endl;
  cout << "find 2 is " << (tree.find(2) ? "true" : "false") << endl;
  tree.remove(2);
  tree.midOrder();
  // cout << "after delete 2, find 2 is " << (tree.find(2) ? "true" : "false")
  //      << endl;

  // cout << endl;
  // cout << "find 3 is " << (tree.find(3) ? "true" : "false") << endl;
  // tree.remove(3);
  // cout << "after delete 3, find 3 is " << (tree.find(3) ? "true" : "false")
  //      << endl;

  // cout << endl;
  // cout << "find 21 is " << (tree.find(21) ? "true" : "false") << endl;
  // tree.remove(21);
  // cout << "after delete 21, find 21 is " << (tree.find(21) ? "true" : "false")
  //      << endl;

  // cout << endl;
  // cout << "find 1 is " << (tree.find(1) ? "true" : "false") << endl;
  // cout << "find 22 is " << (tree.find(22) ? "true" : "false") << endl;
  // cout << "find 38 is " << (tree.find(38) ? "true" : "false") << endl;
  return 0;
}