#pragma once
#include <cmath>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

const double __PI__ = 3.141592653589793238462643383279; // PI的取值
const double __angular_accuracy__ = 1e6;  // 用于使三角函数返回值正常显示
const bool __DEG__ = true; // 角度制

/*************************  OPERATOR DEFINE  **********************************/

// Operators that can be used:
//		"cos",  "sin", "tan", "acos", "asin",
//		"atan", "exp", "log10", "log", "PI"

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
 * File: `serialize.cpp`
 */
vector<op> serialize(string str);

/*************************  CALCULATE  ****************************************/

/**
 * File: `balance.cpp`
 */
size_t balance(const vector<op>& serial, const size_t oparen);
vector<op> content_between_parens(const vector<op>& serial, size_t oparen);

/**
 * File: `operate.cpp`
 */
void binaryOp(op_type op, stack<double>& num);
void singleOp(op_type op, stack<double>& num);

/**
 * File: `calculate.cpp`
 */
double calculate(vector<op> serial);

/*************************  INTERFACE  ****************************************/

/**
 * File: `interface.cpp`
 */
double eval_calc(string str);