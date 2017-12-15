#include "calculator.h"

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

double calculate(char str[]) {
  // 考虑基础题模式
  // 实现'+', '-', '*', '/', '^', '!'
  // 不包含`(`和`)`
  vector<op> serial = serialize(str);

  vector<double> number;
  vector<op_type> oper;
  // 1.2 + 2 * 3 / 4 + 2 ^ 3 + 3 !

  for (int i = 0; i < serial.size(); i++) {
    op cur = serial[i];
    switch (cur.type) {
      case NUM:
        number.push_back(cur.val);
        break;
      case FACT:
        singleOp(cur.type, number);
        break;
      case POW:
        oper.push_back(cur.type);
        break;
      case MUL:
      case DIV:
        while (!oper.empty() && oper.back() >= MUL) {
          binaryOp(oper.back(), number);
          oper.pop_back();
        }
        oper.push_back(cur.type);
        break;
      case ADD:
      case SUB:
        while (!oper.empty()) {
          binaryOp(oper.back(), number);
          oper.pop_back();
        }
        oper.push_back(cur.type);
        break;
    }
  }
  // 扫尾
  while (!oper.empty()) {
    op_type cur = oper.back();
    binaryOp(cur, number);
    oper.pop_back();
  }
  // 检验结果
  double result = 0;
  if (number.empty()) {
    throw Invalid_Experission();
  } else {
    result = number.back();
    number.pop_back();
    if (!number.empty()) {
      throw Invalid_Experission();
    }
  }

  return result;
}