#pragma once
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const double __PI__ = 3.1415926535898;

/*************************  OPERATOR DEFINE
 **********************************/

enum op_type {
  NUM,
  PI,
  OPAR,  // 开括号
  ADD,
  SUB,
  MUL,
  DIV,
  POW,   // 乘方
  CPAR,  // 闭括号
  COS,
  SIN,
  TAN,
  ACOS,
  ASIN,
  ATAN,
  EXP,
  LOG,    // 自然对数
  LOG10,  // 常用对数
  FACT,   // 阶乘
  EOL,
  LETTER
};

class op {
 public:
  op_type type;
  double val;
  op(double value) : val(value) { type = NUM; }
  op(op_type T, double value = 0) : type(T), val(value) {}
};

/*************************  PARSE  ********************************************/

/**
 * File: `parse_serialize.cpp`
 */
vector<op> serialize(string str);

/*************************  CALCULATE  ****************************************/

/**
 * File: `calc_balance.cpp`
 */
size_t balance(const vector<op>& serial, const size_t oparen);
vector<op> content_between_parens(const vector<op>& serial, size_t oparen);

/**
 * File: `calc_operate.cpp`
 */
void binaryOp(op_type op, stack<double>& num);
void singleOp(op_type op, stack<double>& num);

/**
 * File: `calc_calculate.cpp`
 */
double calculate(vector<op> serial);

/*************************  INTERFACE  ****************************************/

/**
 * File: `interface.cpp`
 */
double eval_calc(string str);