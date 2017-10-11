/************************************************************
  * Ackermann Function

************************************************************/

#include <iostream>
#include <string>
#include "ulmtint.h"
using namespace std;

ulmtint add(ulmtint A, ulmtint B) {
	cout << A << " + " << B << " = " << A + B << endl;
	return A + B;
}

int main() {
	try {
		cout << ulmtint("1231231asfdw") << endl;
	} catch (InvalidNumberString) {
		cout << "InvalidNumberString" << endl;
	}

	ulmtint a1 = 12345678;
	ulmtint a2 = 87654321;
	add(a1, a2);

	ulmtint b1("9999999");
	ulmtint b2 = 1111111;
	add(b1, b2);

	ulmtint c1("-1234567");
	ulmtint c2 = -7654321;
	add(c1, c2);

	ulmtint d1 = 1234;
	ulmtint d2 = -1234;
	add(d1, d2);

	ulmtint O = 0;
	add(O, d1);
	add(O, O);

	ulmtint in;
	cout << endl;
	cout << "Type in an integer: ";
	cin >> in;
	cout << in << endl;

	return 0;
}
