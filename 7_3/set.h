#pragma once
#include <iostream>
#include <vector>

using namespace std;

// Declaration
template <class elemType>
class set;

template <class elemType>
ostream& operator<<(ostream& os, const set<elemType>& data);

// Definition
template <class elemType>
class set {
    // friend set operator*(const set& a, const set& b);
    //
    // friend set operator+(const set& a, const set& b);
    //
    // friend set operator-(const set& a, const set& b);
    friend ostream & operator<<<>(const ostream &os, const set<elemType> &data);
private:
    vector<elemType> _data;
public:
    set() {}
    set(elemType src[], size_t size) {
        _data.insert(_data.begin(), *src);
    }
};

template <class elemType>
ostream& operator<<(ostream& os, const set<elemType>& data) {
    os << "\n\t";
    for (size_t i = 0; i < data.size(); ++i) {
        os << data[i] << ' ';
    }
    return os;
}
