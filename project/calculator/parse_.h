#pragma once;
#include "stdlib.h"

/**
 * File: `parse_balance.cpp`
 */
string content_between_parens(string str);

/**
 * File: `parse_serialize.cpp`
 */
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

struct op;