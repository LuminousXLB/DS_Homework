#ifndef _ULMTINT_
#define _ULMTINT_
#include <iostream>
#include <list>
#endif

using namespace std;

class ulmtint;
ulmtint operator+ (const ulmtint & A, const ulmtint & B);
istream operator<< (istream & is, ulmtint & dest);
ostream operator>> (ostream & os, const ulmtint & src);

class ulmtint {
	friend ulmtint operator+ (const ulmtint & A, const ulmtint & B);
	friend istream operator<< (istream & is, ulmtint & dest);
	friend ostream operator>> (ostream & os, const ulmtint & src);
private:
	list<char> data;
	bool sgn;
public:
	ulmtint ();
	ulmtint (int num);
	ulmtint operator= (const ulmtint & src);
};
