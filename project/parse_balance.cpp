#include "calculator.h"

using namespace std;

size_t balance(const string &str, const size_t oparen) {
  size_t head = oparen;
  stack<char> pool;
  if (str[oparen] != '(') {
    throw "ERROR: Open Parentheses Not Found [from `balance`]";
  }
  while (char ch = str[head]) {
    if (ch == '(') {
      pool.push('(');
    } else if (ch == ')') {
      if (pool.empty()) {
        throw "ERROR: Invalid Experission [from `balance`] - Parentheses Unbalanced";
      } else {
        pool.pop();
        if (pool.empty()) {
          break;
        }
      }
    }
    if (++head >= str.length()) {
      throw "ERROR: Invalid Experission [from `balance`] - Parentheses Unbalanced";
    }
  }

  return head;
}

string content_between_parens(string str, size_t op) {
  size_t cp = balance(str, op);
  return str.substr(op + 1, cp - op - 1);
}

// int main() {
//   try {
//     string str("asd(f(g()d)hjkl");
//     size_t op = str.find_first_of('(');
//     string ss(content_between_parens(str, op));
//     cout << ss << endl;
//   } catch (string e) {
//     cout << e << endl;
//   }
// }
