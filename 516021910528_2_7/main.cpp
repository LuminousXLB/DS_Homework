#include "seqList.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int generateLength ();

int main() {
    srand(time(NULL));

    seqList<int> listA, listB;

    int lenA = generateLength();
    for (int i = 0; i < lenA; ++i) {
        listA.insert(i, rand());
    }

    cout << "listA\t"<< listA.length();
    listA.traverse();
	cout << endl << endl;
	
    int lenB = generateLength();
    for (int i = 0; i < lenB; ++i) {
        listB.insert(i, rand());
    }

    cout << "listB\t"<< listB.length();
    listB.traverse();
	cout << endl << endl;
	
	seqList<int> listC = listA + listB;
	
	cout << "listC\t"<< listC.length();
    listC.traverse();
	cout << endl << endl;
		
    return 0;
}

int generateLength () {
    int len = 0;
    while (len <=10 || len >= 20) {
        len = rand();
    }
    return len / 2;
}
