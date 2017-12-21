#include "stdafx.h"
#include "calculator.h"

using namespace std;

double calculate(vector<op> serial) {
  // 考虑基础题模式
  // 实现'+', '-', '*', '/', '^', '!'
  // 不包含`(`和`)`

  stack<double> numStack;
  stack<op_type> opStack;
  // 1.2 + 2 * 3 / 4 + 2 ^ 3 + 3 !

  for (size_t i = 0; i < serial.size(); i++) {
    op cur = serial[i];
    switch (cur.type) {
      case NUM:
        numStack.push(cur.val);
        break;
      case PI:
        numStack.push(__PI__);
        break;
      case FACT:
        singleOp(cur.type, numStack);
        break;
      case COS:
      case SIN:
      case TAN:
      case ACOS:
      case ASIN:
      case ATAN:
      case EXP:
      case LOG:
      case LOG10: {
        ++i;
        size_t cparen = balance(serial, i);
		vector<op> cont(serial.begin() + i + 1, serial.begin() + cparen);
        double val = calculate(cont);
        numStack.push(val);
        singleOp(cur.type, numStack);
        i = cparen;
      } break;
      case CPAR:
        while (!opStack.empty() && opStack.top() != OPAR) {
          binaryOp(opStack.top(), numStack);
          opStack.pop();
        }
        if (opStack.top() != OPAR) {
          throw "ERROR: Invalid Experission [from `calculate`] - Parentheses Unbalanced";
		}
		else {
			opStack.pop();
		}
        break;
      case OPAR:
        opStack.push(cur.type);
        break;
      case POW:
        opStack.push(cur.type);
        break;
      case MUL:
      case DIV:
        while (!opStack.empty() && opStack.top() >= MUL) {
          binaryOp(opStack.top(), numStack);
          opStack.pop();
        }
        opStack.push(cur.type);
        break;
      case ADD:
      case SUB:
        while (!opStack.empty() && opStack.top() != OPAR) {
          binaryOp(opStack.top(), numStack);
          opStack.pop();
        }
        opStack.push(cur.type);
        break;
      default:
        throw "TODO: Not Finished [from `calculate`]";
    }
  }
  // 扫尾
  while (!opStack.empty()) {
    op_type cur = opStack.top();
    binaryOp(cur, numStack);
    opStack.pop();
  }
  // 检验结果
  double result = 0;
  if (numStack.empty()) {
    throw "ERROR: Invalid Experission [from `calculate`]";
  } else {
    result = numStack.top();
    numStack.pop();
    if (!numStack.empty()) {
      throw "ERROR: Invalid Experission [from `calculate`]";
    }
  }

  return result;
}