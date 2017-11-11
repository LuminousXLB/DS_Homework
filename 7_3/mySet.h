#pragma once
#include <iostream>
using namespace std;

int max(int a, int b) {
	return (a > b) ? a : b;
}

template <class T> class mySet;
template <class T> ostream & operator<<(ostream & os, const mySet<T> & pr);
template <class T> mySet<T> operator+(const mySet<T>& seq1, const mySet<T>& seq2);
template <class T> mySet<T> operator*(const mySet<T>& seq1, const mySet<T>& seq2);
template <class T> mySet<T> operator-(const mySet<T>& seq1, const mySet<T>& seq2);

template <class T>
class mySet
{
	friend ostream & operator<<<>(ostream & os, const mySet<T> & pr);
	friend mySet<T> operator+<>(const mySet<T> & seq1, const mySet<T> & seq2);
	friend mySet<T> operator*<>(const mySet<T> & seq1, const mySet<T> & seq2);
	friend mySet<T> operator-<>(const mySet<T> & seq1, const mySet<T> & seq2);
public:
	mySet & operator=(const mySet & other);
	T & operator[](const int & index);
	const T & operator[](const int & index) const;

	mySet(T array[], int n);
	mySet(const mySet & other);
	~mySet();
private:
	T * seq;
	int scale;

	void InsertSort(T sort[], int n);
	int duplicateRemoval(T seq[], int n);
};

template<class T>
mySet<T> & mySet<T>::operator=(const mySet & other) {
	if (this != &other) {
		delete[] seq;
		scale = other.scale;
		seq = new T[scale];
		for (int i = 0; i < scale; i++) {
			seq[i] = other.seq[i];
		}
	}
	return *this;
}

template<class T>
T & mySet<T>::operator[](const int & index) {
	return seq[index];
}

template<class T>
const T & mySet<T>::operator[](const int & index) const {
	return seq[index];
}

template <class T>
mySet<T>::mySet(T array[], int n) {
	InsertSort(array, n);
	scale = duplicateRemoval(array, n);
	seq = new T[scale];
	for (int i = 0; i < scale; i++) {
		seq[i] = array[i];
	}
}

template<class T>
mySet<T>::mySet(const mySet & other) {
	scale = other.scale;
	seq = new T[scale];
	for (int i = 0; i < scale; i++) {
		seq[i] = other.seq[i];
	}
}

template <class T>
mySet<T>::~mySet() {
	delete[] seq;
}

template<class T>
void mySet<T>::InsertSort(T sort[], int n) {
	T temp;
	int k, i;

	for (k = 1; k < n; k++) {
		temp = sort[k];
		for (i = k; i > 0 && temp <= sort[i - 1]; i--) {
			sort[i] = sort[i - 1];
		}
		sort[i] = temp;
	}
}

template <class T>
int mySet<T>::duplicateRemoval(T seq[], int n) {
	int i = 1, step = 1;
	for (i = 1; i < n; i++) {
		if (seq[i] == seq[i - step]) {
			step++;
		} else {
			seq[i - step + 1] = seq[i];
		}
	}
	n -= --step;
	return n;
}

template <class T>
ostream & operator<<(ostream & os, const mySet<T> & pr) {
	char span = '\t';
	for (int i = 0; i < pr.scale; i++) {
		os << pr[i] << span;
	}
	return os;
}

template <class T>
mySet<T> operator+(const mySet<T>& seq1, const mySet<T>& seq2) {
	T * res = new T[max(seq1.scale, seq2.scale)];
	int i = 0, j = 0, k = 0;
	while (i < seq1.scale&&j < seq2.scale) {
		if (seq1[i] < seq2[j]) {
			i++;
		} else if (seq1[i] > seq2[j]) {
			j++;
		} else {
			res[k] = seq1[i];
			i++, j++, k++;
		}
	}

	return mySet<T>(res, k);
}

template <class T>
mySet<T> operator*(const mySet<T>& seq1, const mySet<T>& seq2) {
	T * res = new T[seq1.scale + seq2.scale];
	int i = 0, j = 0, k = 0;
	while (i < seq1.scale&&j < seq2.scale) {
		if (seq1[i] < seq2[j]) {
			res[k] = seq1[i];
			i++;
		} else if (seq1[i] > seq2[j]) {
			res[k] = seq2[j];
			j++;
		} else {
			res[k] = seq1[i];
			i++, j++;
		}
		k++;
	}
	for (; i < seq1.scale; i++, k++) {
		res[k] = seq1[i];
	}
	for (; j < seq2.scale; j++, k++) {
		res[k] = seq2[j];
	}
	return mySet<T>(res, k);
}

template <class T>
mySet<T> operator-(const mySet<T>& seq1, const mySet<T>& seq2) {
	T * res = new T[max(seq1.scale, seq2.scale)];
	int i = 0, j = 0, k = 0;
	while (i < seq1.scale&&j < seq2.scale) {
		if (seq1[i] < seq2[j]) {
			res[k] = seq1[i];
			i++; k++;
		} else if (seq1[i] > seq2[j]) {
			j++;
		} else {
			i++, j++;
		}
	}
	for (; i < seq1.scale; i++, k++) {
		res[k] = seq1[i];
	}
	return mySet<T>(res, k);
}
