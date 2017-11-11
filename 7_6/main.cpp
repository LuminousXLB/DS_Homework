#include "ooot.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int arr[] = { 345, 43, 56, 456, 7 };

    ooot<int> ul(arr, 5);

    for (size_t i = 0; i < 5; i++) {
        cout << ul.search(arr[i]) << endl;
    }
    cout << ul.search(0) << endl;
    return 0;
}
