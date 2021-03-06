#ifndef _ULMTINT_
#define _ULMTINT_
#include <iostream>
#include <list>
#include <string>
#endif

using namespace std;

// const string DEBUG = "DEBUG\t";

/***********************************************************/
// DECLARATION
/***********************************************************/

class InvalidNumberString {};
class ulmtint;

istream & operator>> (istream & is, ulmtint & dest);
ostream & operator<< (ostream & os, const ulmtint & src);
ulmtint operator+ (const ulmtint & oa, const ulmtint & ob);

class ulmtint {
	friend ulmtint operator+ (const ulmtint & oa, const ulmtint & ob);
	friend istream & operator>> (istream & is, ulmtint & dest);
	friend ostream & operator<< (ostream & os, const ulmtint & src);
private:
	list<char> data_;
	bool sgn_;
	bool absmt(const ulmtint & a, const ulmtint & b);
public:
	ulmtint () {};
	ulmtint (int num);
	ulmtint (string str);
	ulmtint & operator= (const ulmtint & src);
};

/***********************************************************/
// IMPLEMENTATION
/***********************************************************/

bool ulmtint::absmt(const ulmtint & a, const ulmtint & b) {
	// compare abs of a & b
	// if abs(a) > abs(b) return true
	const list<char> & na = a.data_;
	const list<char> & nb = b.data_;

	if (na.size() > nb.size()) {
		return true;
	} else if (na.size() < nb.size()) {
		return false;
	} else {
		typename list<char>::const_iterator aitr = a.data_.begin();
		typename list<char>::const_iterator aitre = a.data_.end();
		typename list<char>::const_iterator bitr = b.data_.begin();
		typename list<char>::const_iterator bitre = b.data_.end();
		do {
			if (*aitr > *bitr) {
				return true;
			} else if (*aitr < *bitr) {
				return false;
			}
			++aitr, ++bitr;
		} while (aitr != aitre && bitr != bitre);
	}

	return false;
}

ulmtint::ulmtint(int num) {
	// constructor
	if (num < 0) {
		sgn_ = 1;
		num = -num;
	} else {
		sgn_ = 0;
	}
	string str = to_string(num);
	for (size_t i = 0; i < str.length(); i++) {
		data_.push_front(str[i]-'0');
	}
}

ulmtint::ulmtint(string str) {
	// constructor
	sgn_ = str[0] == '-' ? 1: 0;
	size_t i = sgn_;

	for (; str[i] == '0' && i<str.length(); i++);
	for (; i < str.length(); i++) {
		if(str[i] >= '0' && str[i] <= '9') {
			data_.push_front(str[i]-'0');
		} else {
			throw InvalidNumberString();
		}
	}
}

ulmtint & ulmtint::operator= (const ulmtint & src) {
	this -> data_ = src.data_;
	this -> sgn_ = src.sgn_;
	return *this;
}

istream & operator>> (istream & is, ulmtint & dest) {
	dest.data_.clear();
	char tmp;

	// Skip the space character
	do {
		tmp = is.get();
	} while (isspace(tmp));

	// Get tht first char and check the symbol.
	if (tmp == '-') {
		dest.sgn_ = 1;
		tmp = is.get();
	} else {
		dest.sgn_ = 0;
	}

	// Skip 0s at the beginning
	while(tmp == '0') {
		tmp = is.get();
	}

	// read until non-numerate character
	while(tmp >= '0' && tmp <= '9') {
		dest.data_.push_front(tmp - '0');
		tmp = is.get();
	}

	return is;
}

ostream & operator<< (ostream & os, const ulmtint & src) {
	// 其实list是个双链表，直接itr从end往回输出就好了，但是题里要求是单链表就很尴尬
	if (!src.data_.size()) {
		// if size == 0, os << 0;
		os << 0;
		return os;
	}

	if (src.sgn_) {
		// print symbol
		os << '-';
	}

	// define temporary container & iterator
	list<char> copy;
	typename list<char>::const_iterator itr = src.data_.begin();
	typename list<char>::const_iterator itre = src.data_.end();

	// reverse the list
	do {
		copy.push_front(*itr + '0');
		++itr;
	} while (itr != itre);

	// print the list
	itr = copy.begin();
	itre = copy.end();

	while (itr != itre) {
		os << *itr;
		++itr;
	}

	return os;
}

ulmtint operator+ (const ulmtint & oa, const ulmtint & ob) {
	ulmtint ret;

	// if one of the operands is 0, return the other one
	if (!oa.data_.size()) {
		return oa;
	} else if (!ob.data_.size()) {
		return ob;
	}

	// compare the abs, let the larger one be a
	const ulmtint & a = ret.absmt(oa, ob) ? oa: ob;
	const ulmtint & b = ret.absmt(oa, ob) ? ob: oa;

	//  define refereneces for covenience
	list<char> & sum = ret.data_;

	// define iterator
	typename list<char>::const_iterator aitr = a.data_.begin();
	typename list<char>::const_iterator aitre = a.data_.end();
	typename list<char>::const_iterator bitr = b.data_.begin();
	typename list<char>::const_iterator bitre = b.data_.end();

	// initilize temporary variables
	short int digit = 0, carry = 0;

	// choose from add and subtract
	short int flag = a.sgn_ + b.sgn_;
	if (flag == 1) {
		// subtraction
		do {
			digit = *aitr - *bitr + carry;
			carry = 0;
			while (digit < 0) {
				--carry;
				digit += 10;
			}
			sum.push_back(digit);
			++aitr, ++bitr;
		} while (aitr != aitre && bitr != bitre);

		if (aitr == aitre && bitr == bitre) {
			ret.sgn_ = a.sgn_;
			if (carry) {
				*sum.end() = 10 - *sum.end();
				ret.sgn_ = b.sgn_;
			}
		} else if (aitr != aitre) {
			do {
				digit = *aitr + carry;
				carry = 0;
				while (digit < 0) {
					--carry;
					digit += 10;
				}
				sum.push_back(digit);
				++aitr;
			} while (aitr != aitre);
		} else {
			throw "Uncaught Error";
		}

		typename list<char>::const_iterator back = ret.data_.end();
		--back;
		while (*back == 0 && ret.data_.size()) {
			ret.data_.pop_back();
			back = ret.data_.end();
			--back;
		}
	} else {
		// addition
		ret.sgn_ = a.sgn_;
		do {
			digit = *aitr + *bitr + carry;
			carry = digit / 10;
			digit %= 10;
			sum.push_back(digit);
			++aitr, ++bitr;
		} while (aitr != aitre && bitr != bitre);

		if (aitr != aitre || bitr != bitre) {
			typename list<char>::const_iterator ritr = aitr == aitre ? bitr: aitr;
			typename list<char>::const_iterator ritre = aitr == aitre ? bitre: aitre;
			do {
				digit = *ritr + carry;
				carry = 0;
				while (digit >= 10) {
					++carry;
					digit -= 10;
				}
				sum.push_back(digit);
				++ritr;
			} while (ritr != ritre);
		}

		if (carry) {
			sum.push_back(carry);
		}
	}

	return ret;
}
