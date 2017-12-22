#include "calculator.h"
#include "stdafx.h"

using namespace std;

const bool __DEBUG__ = true;

int main() {
  cout << "Press Ctrl+C to exit ..." << endl;
  char str[80] = {0};
  cout << "> ";
  while (cin.getline(str, 80)) {
    try {
      cout << eval_calc(str) << endl;
    } catch (char const* err) {
      if (__DEBUG__) {
        cout << err << endl;
      } else {
        cout << "Wrong" << endl;
      }
    }
    cout << "> ";
    cin.clear();
    rewind(stdin);
  }
}