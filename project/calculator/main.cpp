#include <iostream>
#include "calculator.h"

using namespace std;

int main() {
  cout << "Press Ctrl+C to exit..." << endl;
  char str[80] = {0};
  cout << "> ";
  while (cin >> str) {
    cout << calculate(str) << endl;
  }
}