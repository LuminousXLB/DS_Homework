#include <iostream>
#include "closeHashTable.h"

using namespace std;

int main(int argc, char const *argv[]) {
    closeHashTable<int> ht;
    ht.insert(3);
    cout << ht.find(3);
    ht.remove(3);
    cout << ht.find(3);

    return 0;
}
