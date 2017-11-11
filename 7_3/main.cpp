// Homework07_3.cpp : ��������̨Ӧ�ó��������ڵ㡣
//
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "mySet.h"
#define SIZE 15
using namespace std;

int randbet(int inf, int sup) {
	return inf + rand()*(sup - inf + 1) / (RAND_MAX + 1);
}

double randbet(double inf, double sup) {
	return inf + (double)rand()*(sup - inf + 1) / (RAND_MAX + 1);
}

void randassign(int arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = randbet(1, 12);
	}
}

void randassign(double arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = randbet(1.0, 12.0);
	}
}

void randassign(char arr[], int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = randbet('a', 'n');
	}
}


int main() {
	srand(time(NULL));

	int a1[SIZE], a2[SIZE];
	double a3[SIZE], a4[SIZE];
	char a5[SIZE], a6[SIZE];

	randassign(a1, SIZE);
	randassign(a2, SIZE);
	randassign(a3, SIZE);
	randassign(a4, SIZE);
	randassign(a5, SIZE);
	randassign(a6, SIZE);

	mySet<int> s1(a1, SIZE), s2(a2, SIZE);
	mySet<double> s3(a3, SIZE), s4(a4, SIZE);
	mySet<char> s5(a5, SIZE), s6(a6, SIZE);

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s1 + s2 << endl;
	cout << s1 - s2 << endl;
	cout << s1*s2 << endl;
	cout << endl;

	cout << s3 << endl;
	cout << s4 << endl;
	cout << s3 + s4 << endl;
	cout << s3 - s4 << endl;
	cout << s3*s4 << endl;
	cout << endl;

	cout << s5 << endl;
	cout << s6 << endl;
	cout << s5 + s6 << endl;
	cout << s5 - s6 << endl;
	cout << s5*s6 << endl;
	cout << endl;

	return 0;
}
