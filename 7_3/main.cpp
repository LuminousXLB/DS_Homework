#include "set.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int arr[] = { 34, 43, 56, 23 };

    set<int> A(arr, 4);
    cout << A << endl;
    return 0;
}
