#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
  // freopen("data.in", "r", stdin);
  Matrix<int> A = input_matrix<int>();
  Matrix<int> B = input_matrix<int>();
  cout << endl;

  printMatrix(elementSub(A, B));
  cout << endl;

  printMatrix(numAdd(1, A));
  cout << endl;

  printMatrix(mul(A, B));
  cout << endl;
  
  cout << getValue(A) << endl;

  del_matrix(A);
  del_matrix(B);
  return 0;
}