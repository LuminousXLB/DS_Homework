#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <class T>
void printArray(T data[], int size);

template <class T>
T *RecursiveBS(T data[], int size, T elem);

template <class T>
int BinarySearch(T data[], int size, T elem);


const int arraysize = 8;
int main(int argc, char const *argv[]) {
    srand(time(NULL));
    double data[arraysize] = { 0, 1, 2, 3, 4, 5, 6, 7 };

    printArray(data, arraysize);

    while (true) {
        double i = rand() % arraysize;
        double d = rand() % 2;
        cout << i + d / 2 << '\t' << BinarySearch(data, arraysize, i + d / 2) << endl;
    }

    // for (int i = 0; i < arraysize; ++i) {
    //     cout << BinarySearch(data, arraysize, data[i]) << endl;
    // }
    //
    // for (int i = 0; i < arraysize; ++i) {
    //     cout << BinarySearch(data, arraysize, data[i] + 0.1) << endl;
    // }

    return 0;
}


template <class T>
void printArray(T data[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << data[i] << '\t';
    }
    cout << endl;
}


template <class T>
T *RecursiveBS(T data[], int size, T elem) {
    int mid = size / 2;

    if (data[mid] == elem) {
        return &data[mid];
    } else if (size == 1) {
        return NULL;
    } else if (data[mid] > elem) {
        return RecursiveBS(data, mid, elem);
    } else {
        return RecursiveBS(data + mid, size - mid, elem);
    }
}


template <class T>
int BinarySearch(T data[], int size, T elem) {
    T *ret = RecursiveBS(data, size, elem);

    if (ret) {
        return ret - data;
    } else {
        return -1;
    }
}
