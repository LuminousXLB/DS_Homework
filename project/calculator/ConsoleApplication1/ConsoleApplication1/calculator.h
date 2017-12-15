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
	POW,   // �˷�
	FACT,  // �׳�
	EOL
};

struct op {
	op_type type;
	double val;
	op(double value) : val(value) { type = NUM; }
	op(op_type T, double value = 0) : type(T), val(value) {}
};

// �ַ�������ֵת��������������ֵ��Ϊ˫���ȸ�������������
double string_to_double(char str[], int len = -2);

// �ַ�����
op_type classify_character(char c);

// �����ַ���Ϊ����������
vector<op> serialize(char str[]);

// ���㺯��
void binaryOp(op_type op, vector<double>& num);
void singleOp(op_type op, vector<double>& num);
double factorial(double num);
 