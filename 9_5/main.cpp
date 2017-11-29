#include <iostream>
#include "closeHashTable.h"

using namespace std;

size_t key(const int& a) { return a; }

int main(int argc, char const* argv[]) {
  // 设定随机数种子
  // srand(time(NULL));

  closeHashTable<int> ht();

  return 0;
}