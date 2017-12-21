#include "calculator.h"

double findvalue(vector<op> serial, double x) {
  for (size_t i = 0; i < serial.size(); ++i) {
    if (serial[i].type == VAR) {
      serial[i] = op(x);
    }
  }
  return calculate(serial);
}

double find_next_x(vector<op> serial, double x, double step) {
  double y = findvalue(serial, x);
  if (fabs(y) < __solution_accuracy__) {
    throw x;
  }
  double y2 = findvalue(serial, x + step);
  if (fabs(y2) < __solution_accuracy__) {
    throw x + step;
  }
  double slope = (y2 - y) / step;
  return x - (y / slope);
}

double findx(vector<op> serial, double x0, double step) {
  try {
    for (size_t i = 0; i < 65537; ++i) {
      x0 = find_next_x(serial, x0, step);
    }
  } catch (double x) {
    return x;
  }
  return x0;
}

double solve(vector<op> serial) {
  double x0;
  cout << "Set the starting point: ";
  cin >> x0;
  return findx(serial, x0);
}