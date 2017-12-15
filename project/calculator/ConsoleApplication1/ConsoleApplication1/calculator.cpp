#include "stdafx.h"
#include "calculator.h"

double string_to_double(char str[], int len) {
	// �ַ�������ֵת������
	// ������ֵ��Ϊ˫���ȸ�������������

	bool is_negative = str[0] == '-';  // ���ַ��Ƿ�Ϊ����
	bool is_float = false;             // �Ƿ���ֹ�С����

	double significant = 0;
	int exponent = 0;

	// ��������
	for (int i = is_negative; str[i] != '\0' && len != 0; ++i, --len) {
		// �����ַ�Ϊ���ţ����[1]��ʼ�����������[0]��ʼ����
		if (str[i] == '.') {
			// ����С����
			if (is_float) {
				// ֮ǰ�Ѿ���ȡ��С���㣬С�����ظ�������ʧ���׳�����
				throw Invalid_Number();
			} else {
				// û�г��ֹ�С����
				is_float = true;
			}
		} else if (str[i] >= '0' && str[i] <= '9') {
			// ����������
			significant = significant * 10 + (str[i] - '0');
			exponent += is_float;
		} else {
			throw Invalid_Number();
		}
	}

	// �ϳ���ֵ
	if (is_negative) {
		return -1 * significant * pow(10, -exponent);
	} else {
		return significant * pow(10, -exponent);
	}
}

op_type classify_character(char c) {
	// �ַ����ຯ��
	if (c >= '0' && c <= '9' || c == '.') {
		return NUM;
	}
	switch (c) {
	case '+':
		return ADD;
		break;
	case '-':
		return SUB;
		break;
	case '*':
		return MUL;
		break;
	case '/':
		return DIV;
		break;
	case '^':
		return POW;
		break;
	case '!':
		return FACT;
		break;
	case '\0':
		return EOL;
		break;
	default:
		throw Invalid_Experission();
	}
}


vector<op> serialize(char str[]) {
	// �����ַ���Ϊ����������
	vector<op> serial;

	while (str[0] != '\0') {
		op_type type = classify_character(str[0]);
		if (type) {
			// ��Ϊ�����
			serial.push_back(op(type));
			++str;
		} else {
			// ����Ϊ��
			int i = 1;
			while (!(type = classify_character(str[i])) && str[i] != '\0') {
				++i;
			}
			double value = string_to_double(str, i);
			serial.push_back(op(value));
			str += i;
		}
	}

	return serial;
}

void binaryOp(op_type op, vector<double>& num) {
	// �����Ԫ�����������
	// ��ȡ����������
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
	// ��������
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
	// ������������������
	// ��ȡһ��������
	double num1;
	if (num.empty()) {
		throw Invalid_Experission();
	} else {
		num1 = num.back();
		num.pop_back();
	}
	// һԪ����
	switch (op) {
	case FACT:
		num.push_back(factorial(num1));
		break;
	}
}

double factorial(double num) {
	// �׳��㷨
	double ret = 1;
	while (num > 0) {
		ret *= num;
		--num;
	}
	return ret;
}
