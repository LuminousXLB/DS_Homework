#include "calculator.h"

using namespace std;

double calculate(vector<op> serial) {
  // 考虑基础题模式
  // 实现'+', '-', '*', '/', '^', '!'
  // 不包含`(`和`)`

  stack<double> number;
  stack<op_type> oper;
  // 1.2 + 2 * 3 / 4 + 2 ^ 3 + 3 !

  for (size_t i = 0; i < serial.size(); i++) {
    op cur = serial[i];
    switch (cur.type) {
      case NUM:
        number.push(cur.val);
        break;
      case FACT:
        singleOp(cur.type, number);
        break;
      case POW:
        oper.push(cur.type);
        break;
      case MUL:
      case DIV:
        while (!oper.empty() && oper.top() >= MUL) {
          binaryOp(oper.top(), number);
          oper.pop();
        }
        oper.push(cur.type);
        break;
      case ADD:
      case SUB:
        while (!oper.empty()) {
          binaryOp(oper.top(), number);
          oper.pop();
        }
        oper.push(cur.type);
        break;
      default:
        throw "TODO: Not Finished";
    }
  }
  // 扫尾
  while (!oper.empty()) {
    op_type cur = oper.top();
    binaryOp(cur, number);
    oper.pop();
  }
  // 检验结果
  double result = 0;
  if (number.empty()) {
    throw "Invalid Experission";
  } else {
    result = number.top();
    number.pop();
    if (!number.empty()) {
      throw "Invalid Experission";
    }
  }

  return result;
}