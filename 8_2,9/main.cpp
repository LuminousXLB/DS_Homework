#include <iostream>
#include "BinarysearchTree.h"

using namespace std;

int main() {
  int a[] = {10, 8, 6, 21, 87, 56, 4, 0, 11, 3, 22, 7, 5, 34, 1, 2, 9};

  BinarySearchTree<int> tree;

  for (int i = 0; i < 17; ++i) {
    tree.insert(a[i]);
  }

  tree.print();
  cout << "the 1st max is " << tree.findIthMax(1) << endl;
  cout << "the " << 6 << "th max is " << tree.findIthMax(6) << endl;
  cout << "the " << 17 << "th max is " << tree.findIthMax(17) << endl;

  tree.removeLessT(4);
  cout << "aftre remove elements less than 4," << endl;
  tree.print();

  return 0;
}
