#include "calculator.h"

using namespace std;

double factorial(double num) {
  // 阶乘算法
  double ret = 1;
  while (num > 0) {
    ret *= num;
    --num;
  }
  return ret;
}

void binaryOp(op_type op, stack<double>& num) {
  // 计算二元运算符运算结果
  // 读取两个操作数
  double num1, num2;
  if (num.empty()) {
    throw "ERROR: Invalid Experission [from `binaryOp`]";
  } else {
    num1 = num.top();
    num.pop();
  }
  if (num.empty()) {
    throw "ERROR: Invalid Experission [from `binaryOp`]";
  } else {
    num2 = num.top();
    num.pop();
  }
  // 进行运算
  switch (op) {
    case ADD:
      num.push(num2 + num1);
      break;
    case SUB:
      num.push(num2 - num1);
      break;
    case MUL:
      num.push(num2 * num1);
      break;
    case DIV:
      num.push(num2 / num1);
      break;
    case POW:
      num.push(pow(num2, num1));
      break;
    default:
      throw "ERROR: Invalid Operator [from `binaryOp`]";
  }
}

void singleOp(op_type op, stack<double>& num) {
  // 单操作数操作符运算
  // 读取一个操作数
  double num1;
  if (num.empty()) {
    throw "ERROR: Invalid Experission";
  } else {
    num1 = num.top();
    num.pop();
  }
  // 一元运算
  switch (op) {
    case FACT:
      num.push(factorial(num1));
      break;
    case COS:
      num.push(cos(num1));
      break;
    case SIN:
      num.push(sin(num1));
      break;
    case TAN:
      num.push(tan(num1));
      break;
    case ACOS:
      num.push(acos(num1));
      break;
    case ASIN:
      num.push(asin(num1));
      break;
    case ATAN:
      num.push(atan(num1));
      break;
    case EXP:
      num.push(exp(num1));
      break;
    case LOG:
      num.push(log(num1));
      break;
    case LOG10:
      num.push(log10(num1));
      break;
    default:
      throw "ERROR: Invalid Operator [from `singleOp`]";
  }
}
