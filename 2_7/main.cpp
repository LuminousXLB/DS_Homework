/************************************************************
  * Sample of merging 2 seqList

    Generate 2 seqLists, listA & listB, randomly and then merge them to listC.

  ** Function
    ```
    int generateLength ();
    ```
    give a random number in a certain range which acts as the length of a seqList

************************************************************/

#include "seqList.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int generateLength ();

int main() {

//  Generate seqList A

    srand(time(NULL));

    seqList<int> listA, listB;

    int lenA = generateLength();
    for (int i = 0; i < lenA; ++i) {
        listA.insert(i, rand());
    }

    cout << "listA\t"<< listA.length();
    listA.traverse();
	cout << endl << endl;

//  Generate seqList B

    int lenB = generateLength();
    for (int i = 0; i < lenB; ++i) {
        listB.insert(i, rand());
    }

    cout << "listB\t"<< listB.length();
    listB.traverse();
	cout << endl << endl;

//	merge

	seqList<int> listC = listA + listB;

	cout << "listC\t"<< listC.length();
    listC.traverse();
	cout << endl << endl;

    return 0;
}

int generateLength () {
    return rand % 20 + 5 ;
}
