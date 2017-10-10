/************************************************************
  * Pascal :inter
  	  begin ... end
	  if ... then ... (else ...

  ** Function
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

enum sep {BEGIN, END};
enum ctrl {IF, THEN, ELSE};
struct stat {
	bool BEGIN_END = true, IF_THEN_ELSE = true;
};
class FILE_OPEN_FAILED {};

stat check (string filename) {
	ifstream reader(filename.c_str());
	if(!reader) {
		throw FILE_OPEN_FAILED();
	}

	stack<sep> separator;
	stack<ctrl> proctrl;
	stat ret;
	string word;
	while (reader >> word) {
		if (word == "begin") {
			separator.push(BEGIN);
		} else if (word == "end" && ret.BEGIN_END) {
			if (separator.empty()) {
				ret.BEGIN_END = false;
			} else {
				separator.pop();
			}
		} else if (word == "if") {
			if (!proctrl.empty() && proctrl.top() == THEN) {
				proctrl.pop();
			}
			proctrl.push(IF);
		} else if (word == "then" && ret.IF_THEN_ELSE) {
			if (proctrl.empty() || proctrl.top() == THEN) {
				ret.IF_THEN_ELSE = false;
			} else {
				proctrl.pop();
				proctrl.push(THEN);
			}
		}

		if (!ret.BEGIN_END && !ret.IF_THEN_ELSE) {
			break;
		}
	}

	return ret;
}

int main() {
	return 0;
}
