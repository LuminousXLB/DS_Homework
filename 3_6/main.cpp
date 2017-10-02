/************************************************************
  * Ackermann Function
    A(m, n) =
      n + 1             when m = 0
      A(m-1, 1)         when m != 0, n = 0
      A(m-1, A(m, n-1)) when m != 0, n != 0

  ********** Alogrithm with recursions **********

  ** Function
    ```
    int Ackerman(int m, int n);
    ```
    The most primitive algorithm.

  ** Function
    ```
    int Ackerman_opt(int m, int n);
    ```
    I did some calculations and got some expressions which are closer to the answer.

        when m = 1, n >= 1
            A(1, n) = A(0, A(1, n-1)) = A(1, n-1) + 1
         => A(1, n) = A(1, n-1) + 1 = A(1, n-2) + 2 = ... = A(1, 1) + n-1
                    = n+2

        when m = 2, n >= 1
            A(2, n) = A(1, A(2, n-1)) = A(2, n-1) + 2
         => A(2, n) = A(2, n-1) + 2 = A(2, n-2) + 4 = ... = A(2, 1) + 2(n-1)
                    = 2n+3

        when m = 3, n >= 1
            A(3, n) = A(2, A(3, n-1)) = 2*A(3, n-1) + 3
         => A(3, n) = 2*A(3, n-1) + 3
         => A(3, n) + 3 = 2*[A(3, n-1) + 3]
         => A(3, n) = [A(3, 1) + 3]*2^(n-1) - 3
                    = 2^(n+3) - 3

    But for m == 4, I can only get following recursive relationship.
        when m = 4, n >= 1
            A(4, n) = A(3, A(4, n-1)) = 2^[A(4, n-1) + 3] - 3

    With the growth of m, the expression becomes much more complicated. I believe that the growth rate of the function makes it meaningless to do more calculations.
    In spite of this, I still did a little optimization for m > 4. On the base of the primitive function, I found that
        when m > 1, n = 0
            A(m, 0) = A(m-1, 1) (m-1 > 0)
                    = A(m-2, A(m-1, 0))
    This may reduce the number of recursions with little success.

  ********** Alogrithm without recursions **********

  ** Struct
    ```
    struct arg { int m, n; };
    ```
    Define a structure with m and n which acts as elemType of the stack. In this way, I avoid operating two stacks with the same operation at the same time.

  ** Function
    ```
    int Ackerman_stack(int m, int n);
    ```
    Initilize - Get m and n.
                Push them into the stack.
    Loop      - Access next element.
                If A(m. n) can be found in data or it can be calculated during the loop, remove it from the stack.
                Or A(m, n) can must be expressed with some A(a, b).
                    If it can be found in data, return it.
                    Or push {a, b} into the stack.
    Return    - When the Loop is finished, A(m, n) can be found by data[m][n]

************************************************************/

#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int Ackerman(int m, int n);
int Ackerman_opt(int m, int n);

struct arg {
    int m, n;
};

const int SIZE = 10000;
int data[SIZE][SIZE] = {0};
stack<arg> cache;

int getData(int m, int n);
int Ackerman_stack(int m, int n);


void printAck(int m, int n) {
    cout << m << '\t' << n << '\t' << Ackerman(m, n) << '\t' << Ackerman_stack(m, n) << endl;
}

int main()
{
    cout << "m" << '\t' << "n" << '\t' << "opt" << '\t' << "stack" << endl;
    for (int i = 0; i <= 3; i++) {
        for (int j = 0; j <= 4; j++) {
            printAck(i, j)
        }
    }
    printAck(4, 0);
    printAck(4, 1);

    return 0;
}

int Ackerman(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        return Ackerman(m - 1, 1);
    } else {
        return Ackerman(m - 1, Ackerman(m, n - 1));
    }
}

int Ackerman_opt(int m, int n) {
    if (m == 1 && n >= 1) {
        return n + 2;
    } else if (m == 2 && n >= 1) {
        return 2*n + 3;
    } else if (m == 3 && n >= 1) {
        return pow(2, n + 3) - 3;
    } else if (m == 4 && n >= 1) {
        // 2^[A(4, n-1) + 3] - 3
        return pow(2, Ackerman_opt(4, n - 1)) - 3;
    }

    if (m == 0) {
        return n + 1;
    } else if (n == 0) {
        if (m == 1) {
            return Ackerman_opt(m - 1, 1);
        } else {
            return Ackerman_opt(m - 2, Ackerman_opt(m - 1, 0));
        }
    } else {
        return Ackerman_opt(m - 1, Ackerman_opt(m, n - 1));
    }
}

int getData(int m, int n) {
    int ret = data[m][n];
    if (!ret) {
        arg uncalculated = {m, n};
        cache.push(uncalculated);
    }
    return ret;
}

int Ackerman_stack(int m, int n) {
    arg enter = {m, n};
    cache.push(enter);

    while (!cache.empty()) {
        arg cur = cache.top();
        int m = cur.m, n = cur.n;

        if (data[m][n]) {
            cache.pop();
        } else {
            if (m == 0) {
                data[m][n] = n + 1;
            } else if (n == 0) {
                data[m][n] = getData(m - 1, 1);
            } else {
                int nn = getData(m, n - 1);
                if (nn) {
                    data[m][n] = getData(m - 1, nn);
                }
            }
            if (data[m][n]) {
                cache.pop();
            }
        }

    }
    return data[m][n];
}
