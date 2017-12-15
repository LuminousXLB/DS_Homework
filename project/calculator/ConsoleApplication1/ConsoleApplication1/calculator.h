#pragma once
#include <vector>
#include <cmath>

using namespace std;

class Invalid_Number {};
class Invalid_Operator {};
class Invalid_Experission {};

enum op_type {
	NUM,
	ADD,
	SUB,
	MUL,
	DIV,
	POW,   // 乘方
	FACT,  // 阶乘
	EOL
};

struct op {
	op_type type;
	double val;
	op(double value) : val(value) { type = NUM; }
	op(op_type T, double value = 0) : type(T), val(value) {}
};

// 字符串向数值转换函数，所有数值作为双精度浮点数参与运算
double string_to_double(char str[], int len = -2);

// 字符分类
op_type classify_character(char c);

// 整理字符串为操作符序列
vector<op> serialize(char str[]);

// 运算函数
void binaryOp(op_type op, vector<double>& num);
void singleOp(op_type op, vector<double>& num);
double factorial(double num);
 