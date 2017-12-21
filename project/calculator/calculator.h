#pragma once
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "calc_.h"
#include "parse_.h"

using namespace std;

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