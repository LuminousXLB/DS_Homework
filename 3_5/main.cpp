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

enum key {BEGIN, END, IF, THEN, ELSE};

class FILE_OPEN_FAILED {};

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
			
		}

	}

	return true;
}

int main() {
	return 0;
}
