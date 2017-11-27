#include <iostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char const *argv[]) {
  BinaryTree<int> bt(1);
  bt.hierarchicalTraverse();
  return 0;
}
