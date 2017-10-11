#include <stack>

using namespace std;

int main () {
	stack<int> l;
	try {
		l.push(1);
		l.pop();
		l.pop();
		l.pop();
	} catch (Error) {
		
	}


	return 0;
}
