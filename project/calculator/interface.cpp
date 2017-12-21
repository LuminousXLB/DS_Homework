#include "stdafx.h"
#include "calculator.h"

using namespace std;

double eval_calc(string str) {
  bool eq_flag = false;
  vector<op> serial = serialize(str, eq_flag);
  if (eq_flag) {
    return solve(serial);
  } else {
    return calculate(serial);
  }
}
