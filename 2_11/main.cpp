/************************************************************
  * Ackermann Function

************************************************************/

#include <iostream>
#include <string>
#include "ulmtint.h"
using namespace std;

void add(ulmtint A, ulmtint B) {
	cout << A << "\t+\t" << B << "\t=\t" << A + B << endl;

}

int main() {
	ulmtint a = 123456789;
	ulmtint b = 987654321;
	ulmtint c = -123400000;
	ulmtint d = -4567;
	ulmtint o = 0;

	// add(a, b);
	// add(c, d);
	add(a, c);
	// add(a, d);
	// add(o, a);

	return 0;
}
