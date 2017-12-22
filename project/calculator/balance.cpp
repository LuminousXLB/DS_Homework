#include "calculator.h"
#include "stdafx.h"

using namespace std;

size_t balance(const vector<op> &serial, const size_t oparen) {
  size_t head = oparen;
  stack<op> pool;
  if (serial[oparen].type != OPAR) {
    throw "ERROR: Open Parentheses Not Found [from `balance`]";
  }
  while (true) {
    op cur = serial[head];
    if (cur.type == OPAR) {
      pool.push(OPAR);
    } else if (cur.type == CPAR) {
      if (pool.empty()) {
        throw "ERROR: Invalid Experission [from `balance`] - Parentheses Unbalanced";
      } else {
        pool.pop();
        if (pool.empty()) {
          break;
        }
      }
    }
    if (++head >= serial.size()) {
      throw "ERROR: Invalid Experission [from `balance`] - Parentheses Unbalanced";
    }
  }

  return head;
}

vector<op> content_between_parens(const vector<op> &serial, size_t oparen) {
  size_t cparen = balance(serial, oparen);
  // return serial.substr(op + 1, cparen - op - 1);
  return vector<op>(serial.begin() + oparen + 1,
                    serial.begin() + cparen - oparen - 1);
}
