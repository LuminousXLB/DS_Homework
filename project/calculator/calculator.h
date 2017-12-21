#pragma once
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

/*************************  OPERATOR DEFINE  **********************************/

enum op_type {
  NUM,
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
 * File: `parse_balance.cpp`
 */
string content_between_parens(string str);

/**
 * File: `parse_serialize.cpp`
 */
vector<op> serialize(string str);

/*************************  CALCULATE  ****************************************/

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

double eval_calc(string str) { return calculate(serialize(str)); }
