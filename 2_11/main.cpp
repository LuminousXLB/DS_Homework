/************************************************************
  * Ackermann Function

************************************************************/

#include <iostream>
#include <string>
#include "ulmtint.h"
using namespace std;

ulmtint add(ulmtint A, ulmtint B) {
	cout << A << "\t+\t" << B << "\t=\t" << A + B << endl;
	return A + B;
}

int main() {
	ulmtint a = 123456789;
	ulmtint b = 987654321;
	ulmtint c = -123400000;
	ulmtint d = -56789;
	ulmtint e = 4567;
	ulmtint o = 0;


	// @FIXME 0-0
	// add(a, b);
	// add(c, d);
	add(ulmtint(56789), d);
	// add(o, a);
	// add(o, o);

	return 0;
}
