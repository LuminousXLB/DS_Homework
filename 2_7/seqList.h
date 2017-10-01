/************************************************************
  * Source Code 2-2  Sequence List

  ** Bug
    ```
    int seqList<elemType>::search(const elemType &x) const
    ```
    i is undefined after the loop

  ** Feature
    ```
    void seqList<elemType>::traverse() const
    ```
    give a tab after each element

  ** Feature:
    ```
    template <class elemType>
    seqList<elemType> operator+(const seqList<elemType> &listA, const seqList<elemType> &listB)
    ```
    merge listA & listB

************************************************************/

#include "list.h"

using namespace std;

class OutOfBound {};
class IllegalSize {};

template <class elemType>
class seqList;

template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &listA, const seqList<elemType> &listB);

template <class elemType>
class seqList : public list<elemType> {
	friend seqList<elemType> operator+ <> (const seqList<elemType> &listA, const seqList<elemType> &listB);
  private:
    elemType *data;
    int currentLength;
    int maxSize;
    void doubleSpace();

  public:
    seqList(int initSize = 10);
    ~seqList() {
        delete[] data;
    }
    void clear() {
        currentLength = 0;
    }
    int length() const {
        return currentLength;
    }
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const;
    elemType visit(int i) const;
    void traverse() const;
};

template <class elemType>
void seqList<elemType>::doubleSpace() {
    elemType *tmp = data;
    maxSize *= 2;
    data = new elemType[maxSize];

    for (int i = 0; i < currentLength; ++i) {
        data[i] = tmp[i];
    }
    delete[] tmp;
}

template <class elemType>
seqList<elemType>::seqList(int initSize) {
    if (initSize <= 0) {
        throw IllegalSize();
    }
    data = new elemType[initSize];
    maxSize = initSize;
    currentLength = 0;
}

template <class elemType>
void seqList<elemType>::insert(int i, const elemType &x) {
    if (i < 0 || i > currentLength) {
        throw OutOfBound();
    }
    if (currentLength == maxSize) {
        doubleSpace();
    }
    for (int j = currentLength; j > i; j--) {
        data[j] = data[j - 1];
    }
    data[i] = x;
    ++currentLength;
}

template <class elemType>
void seqList<elemType>::remove(int i) {
    if (i < 0 || i > currentLength - 1) {
        throw OutOfBound();
    }
    for (int j = i; j < currentLength - 1; j++) {
        data[j] = data[j + 1];
    }
    --currentLength;
}

template <class elemType>
int seqList<elemType>::search(const elemType &x) const {
    for (int i = 0; i < currentLength; ++i) {
        if (data[i] == x) {
            return i;
        }
    }
    return -1;
}

template <class elemType>
elemType seqList<elemType>::visit(int i) const {
    if (i < 0 || i > currentLength - 1) {
        throw OutOfBound();
    }
    return data[i];
}

template <class elemType>
void seqList<elemType>::traverse() const {
    cout << endl;
    for (int i = 0; i < currentLength; ++i) {
        cout << data[i] << '\t';
    }
}

template <class elemType>
seqList<elemType> operator+(const seqList<elemType> &listA, const seqList<elemType> &listB) {

	seqList<elemType> merge(listA.length() + listB.length() + 1);  // Initialize a new seqList whose maxLength is the sum of the length of listA & listB

    int i, j;
    for (i = 0; i < listA.length(); ++i) {
        merge.insert(i, listA.visit(i));  // copy the data of listA to merge
    }
    for (j = 0; j < listB.length(); ++j) {
        merge.insert(i + j, listB.visit(j)); // copy the data of listB to merge following that of listA
    }

    return merge;
}
