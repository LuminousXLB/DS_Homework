/************************************************************
    docs in readme.md
************************************************************/

#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

enum key {BEGIN, IF, THEN, ELSE, END};
bool check (string filename);

class FILE_OPEN_FAILED {};

/***********************************************************/

int main() {
	string filename = "Dijkstra.pas";
	try {
		if (check(filename)) {
			cout << "Matching succeed" << endl;
		} else {
			cout << "Matching failed" << endl;
		}
	} catch (FILE_OPEN_FAILED) {
		cout << "Cannot open the file "<< filename << endl;
	}

	return 0;
}

/***********************************************************/

bool check (string filename) {
	ifstream reader(filename.c_str());
	if(!reader) {
		throw FILE_OPEN_FAILED();
	}
	string word;

	stack<key> pool;

	while (reader >> word) {
		if (word == "begin") {
			pool.push(BEGIN);
		} else if (word == "if") {
			pool.push(IF);
		} else if (word == "then") {
			pool.push(THEN);
		} else if (word == "else") {
			pool.push(ELSE);
		} else if (word == "end;" || word == "end.") {

			while (!pool.empty() && pool.top() != BEGIN) {
				key cur = pool.top();
				if (cur == ELSE) {
					pool.pop();
					if (pool.top() == THEN) {
						continue;
					} else {
						return false;
					}
				} else if (pool.top() == THEN) {
					pool.pop();
					if (pool.top() == IF) {
						pool.pop();
					} else {
						return false;
					}
				} else {
					return false;
				}
			}

			if (pool.empty()) {
				return false;
			} else {
				pool.pop();
			}

		}
	}

	return pool.empty();
}
