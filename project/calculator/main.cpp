#include "calculator.h"

using namespace std;

const bool __DEBUG__ = true;

int main() {
  cout << "Press Ctrl+C to exit ..." << endl;
  char str[80] = {0};
  cout << "> ";
  while (cin >> str) {
    try {
      cout << eval_calc(str) << endl;
    } catch (char const * err) {
      if (__DEBUG__) {
        cout << err << endl;
      } else {
        cout << "Wrong" << endl;
      }
    }
    cout << "> ";
  }
}