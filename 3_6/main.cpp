#include <iostream>
#include <cmath>

using namespace std;

int m = 4;
int n = 2;

int Ackerman(int m, int n) {
    cout << m << '\t' << n << endl;

    if (m == 1 && n >= 1) {
        int ret = n + 2;
        // cout << "calculated\t" << ret << endl;
        return ret;
    } else if (m == 2 && n >= 1) {
        int ret = 2*n + 3;
        // cout << "calculated\t" << ret << endl;
        return ret;
    } else if (m == 3 && n >= 1) {
        int ret = pow(2, n + 3) - 3;
        // cout << "calculated\t" << ret << endl;
        return ret;
    }

    if (m == 0) {
        return n + 1;
    } else {
        if (n == 0) {
            if (m == 1) {
                return Ackerman(m - 1, 1);
            } else {
                return Ackerman(m - 2, Ackerman(m - 1, 0));
            }
        } else {
            return Ackerman(m - 1, Ackerman(m, n - 1));
        }
    }
/*
    if (m == 1 && n >= 1) 
        A(1, n) = A(0, A(1, n-1)) = A(1, n-1) + 1
     => A(1, n) = A(1, n-1) + 1 = A(1, n-2) + 2 = ... = A(1, 1) + n-1 = n+2

    if (m == 2 && n >= 1)
        A(2, n) = A(1, A(2, n-1)) = A(2, n-1) + 2
     => A(2, n) = A(2, n-1) + 2 = A(2, n-2) + 4 = ... = A(2, 1) + 2(n-1) = 2n+3

    if (m == 3 && n >= 1)
        A(3, n) = A(2, A(3, n-1)) = 2*A(3, n-1) + 3
     => A(3, n) = 2*A(3, n-1) + 3 => A(3, n) + 3 = 2*[A(3, n-1) + 3] 
     => A(3, n) = [A(3, 1) + 3]*2^(n-1) - 3 = 2^(n+3) - 3

    if (m == 4 && n >= 1)
        A(4, n) = A(3, A(4, n-1)) = 2^[A(4, n-1) + 3] - 3
*/

}

int main()
{
    int A = Ackerman(m, n);
    cout << A << endl;
    return 0;
}
