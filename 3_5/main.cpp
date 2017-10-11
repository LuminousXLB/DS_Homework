/************************************************************
  # Pascal :inter
  	  begin ... end
	  if ... then ... (else ...

  ## Function
    ```
    int Ackerman(int m, int n);
    ```
    The most primitive algorithm.
************************************************************/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>

using namespace std;

const string DEBUG = "DEBUG\t";

enum key {BEGIN, IF, THEN, ELSE, END};
bool check (string filename);

class FILE_OPEN_FAILED {};

int main() {
	if (check("Dijkstra.pas")) {
		cout << "Matching succeed" << endl;
	} else {
		cout << "Matching failed" << endl;
	}

	return 0;
}

/***********************************************************/

bool check (string filename) {
	ifstream reader(filename.c_str());
	if(!reader) {
		throw FILE_OPEN_FAILED();
	}

	stack<key> pool;
	string word;

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
