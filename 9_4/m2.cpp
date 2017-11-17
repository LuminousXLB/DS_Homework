#include <iostream>
#include <cstdlib>
#include <ctime>
#include "matElem.h"

using namespace std;

int (*f)(const int& elem) {
    int hash = 2;

    return hash;
}


int main(int argc, char const *argv[]) {
    // matElem<int> tmp = getRandom(100, 100);
    const int a = 23;

    f(a);
    // key(tmp);

    return 0;
}
