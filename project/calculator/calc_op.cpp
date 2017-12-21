#include "stdlib.h"

using namespace std;

void binaryOp(op_type op, vector<double>& num) {
  // 计算二元运算符运算结果
  // 读取两个操作数
  double num1, num2;
  if (num.empty()) {
    throw Invalid_Experission();
  } else {
    num1 = num.back();
    num.pop_back();
  }
  if (num.empty()) {
    throw Invalid_Experission();
  } else {
    num2 = num.back();
    num.pop_back();
  }
  // 进行运算
  switch (op) {
    case ADD:
      num.push_back(num2 + num1);
      break;
    case SUB:
      num.push_back(num2 - num1);
      break;
    case MUL:
      num.push_back(num2 * num1);
      break;
    case DIV:
      num.push_back(num2 / num1);
      break;
    case POW:
      num.push_back(pow(num2, num1));
      break;
    default:
      throw Invalid_Operator();
  }
}

void singleOp(op_type op, vector<double>& num) {
  // 单操作数操作符运算
  // 读取一个操作数
  double num1;
  if (num.empty()) {
    throw Invalid_Experission();
  } else {
    num1 = num.back();
    num.pop_back();
  }
  // 一元运算
  switch (op) {
    case FACT:
      num.push_back(factorial(num1));
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