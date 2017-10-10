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
#include <stack>
#include <string>

using namespace std;

int main() {
	enum sep {BEGIN, END};
	enum brc {IF, THEN, ELSE};
	stack<sep> S;
	stack<brc> B;
	return 0;
}
