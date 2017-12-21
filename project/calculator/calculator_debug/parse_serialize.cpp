#include "stdafx.h"
#include "calculator.h"

using namespace std;

op_type classify_character(char ch) {
	// 字符分类函数
	switch (ch) {
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
	case '(':
		return OPAR;
		break;
	case ')':
		return CPAR;
		break;
	case '\0':
		return EOL;
		break;
	}

	if ((ch >= '0' && ch <= '9') || ch == '.') {
		return NUM;
	}
	else if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
		return LETTER;
	}
	else {
		cerr << ch << "(" << unsigned(ch) << ")" << endl;
		throw "ERROR: Invalid Character Found [from `classify_character`]";
	}

	return EOL;
}

// string capticalize(string str) {
//   // 用于扩展大小写模糊匹配
//   string cap;
//   char ch = str[0];
//   for (size_t i = 0; i < str.length(); ch = str[++i]) {
//     if (ch > 'a' && ch < 'z') {
//       cap.push_back(ch - 'a' + 'A');
//     }
//   }
//   return cap;
// }

vector<op> serialize(string str) {
	// 整理字符串为操作符序列
	const size_t op_lst_len = 10;
	const size_t op_max_len = 5;
	const static string tr_ops[op_lst_len] = { "cos",  "sin", "tan", "acos", "asin",
									 "atan", "exp", "log10", "log", "PI" };
	const static op tr_lst[op_lst_len] = { COS,  SIN, TAN, ACOS, ASIN,
								 ATAN, EXP, LOG10, LOG, PI };

	vector<op> serial;

	size_t head = -1;
	char ch;
	op_type type;

	while (++head < str.length()) {
		ch = str[head];

		// clog << ch << "(" << unsigned(ch) << ")" << endl;

		if (ch == ' ') continue;
		type = classify_character(ch);

		if (type == LETTER) {
			string sub = str.substr(head, op_max_len);
			string match;
			for (size_t i = 0; i < op_lst_len; ++i) {
				if (sub.find(tr_ops[i]) == 0) {
					serial.push_back(op(tr_lst[i]));
					match = tr_ops[i];
					break;
				}
			}
			if (match.length()) {
				head += match.length() - 1;
			}
			else {
				cerr << ch << "(" << unsigned(ch) << ")" << endl;
				throw "ERROR: Invalid Character Found [from `serialize`]";
			}
		}
		else if (type == NUM) {
			// 若为数
			size_t start = head;
			while (head < str.length()) {
				if (str[head] != ' ' && classify_character(str[head]) != NUM) {
					break;
				}
				head++;
			}

			double value = atof(str.substr(start, head - start).c_str());
			serial.push_back(op(value));

			head--;
		}
		else {
			// 若为运算符
			if (type == SUB) {
				if (serial.empty() || serial.back().type == OPAR) {
					serial.push_back(op(0));
				}
			}
			serial.push_back(op(type));
		}
	}

	return serial;
}
