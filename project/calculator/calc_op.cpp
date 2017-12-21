#include "stdlib.h"

using namespace std;

void binaryOp(op_type op, stack<double>& num) {
  // 计算二元运算符运算结果
  // 读取两个操作数
  double num1, num2;
  if (num.empty()) {
    throw "ERROR: Invalid Experission";
  } else {
    num1 = num.top();
    num.pop();
  }
  if (num.empty()) {
    throw "ERROR: Invalid Experission";
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
      throw "ERROR: Invalid Operator";
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
  }
}

double factorial(double num) {
  // 阶乘算法
  double ret = 1;
  while (num > 0) {
    ret *= num;
    --num;
  }
  return ret;
}