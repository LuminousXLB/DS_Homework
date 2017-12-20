#include "calculator.h"

double string_to_double(char str[], int len) {
  // 字符串向数值转换函数
  // 所有数值作为双精度浮点数参与运算

  bool is_negative = str[0] == '-';  // 首字符是否为负号
  bool is_float = false;             // 是否出现过小数点

  double significant = 0;
  int exponent = 0;

  // 遍历解析
  for (int i = is_negative; str[i] != '\0' && len != 0; ++i, --len) {
    // 若首字符为负号，则从[1]开始遍历，否则从[0]开始遍历
    if (str[i] == '.') {
      // 发现小数点
      if (is_float) {
        // 之前已经读取过小数点，小数点重复，解析失败抛出错误
        throw Invalid_Number();
      } else {
        // 没有出现过小数点
        is_float = true;
      }
    } else if (str[i] >= '0' && str[i] <= '9') {
      // 正常的数字
      significant = significant * 10 + (str[i] - '0');
      exponent += is_float;
    } else {
      throw Invalid_Number();
    }
  }

  // 合成数值
  if (is_negative) {
    return -1 * significant * pow(10, -exponent);
  } else {
    return significant * pow(10, -exponent);
  }
}

op_type classify_character(char c) {
  // 字符分类函数
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
  // 整理字符串为操作符序列
  vector<op> serial;

  while (str[0] != '\0') {
    op_type type = classify_character(str[0]);
    if (type) {
      // 若为运算符
      serial.push_back(op(type));
      ++str;
    } else {
      // 否则为数
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

