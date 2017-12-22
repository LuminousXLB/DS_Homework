#include "calculator.h"
#include "stdafx.h"

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

double normalize(double val) {
  return int(val * __angular_accuracy__ + 0.5) / __angular_accuracy__;
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
      if (__DEG__) {
        num1 = num1 * __PI__ / 180;
      }
      num.push(normalize(cos(num1)));
      break;
    case SIN:
      if (__DEG__) {
        num1 = num1 * __PI__ / 180;
      }
      num.push(normalize(sin(num1)));
      break;
    case TAN:
      if (__DEG__) {
        num1 = num1 * __PI__ / 180;
      }
      num.push(normalize(tan(num1)));
      break;
    case ACOS:
      if (__DEG__) {
        num1 = acos(num1) * 180 / __PI__;
      }
      num.push(num1);
      break;
    case ASIN:
      if (__DEG__) {
        num1 = asin(num1) * 180 / __PI__;
      }
      num.push(num1);
      break;
    case ATAN:
      if (__DEG__) {
        num1 = atan(num1) * 180 / __PI__;
      }
      num.push(num1);
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
