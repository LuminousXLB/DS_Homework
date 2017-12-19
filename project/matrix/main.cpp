#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
  // freopen("data.in", "r", stdin);
  Matrix<int> A();
  A.input();
  Matrix<int> B();
  B.input();
  cout << endl;

  cout << A - B << endl;
  cout << endl;

  cout << A + 1 << endl;

  cout << multi(A, B) << endl;

  cout << A.det() << enl;

  return 0;
}