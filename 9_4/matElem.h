#pragma once

#include <cstdlib>

template <class elemType>
class matElem {
    friend bool operator==<>(const matElem<elemType> &, const matElem<elemType> &);
private:
    unsigned row_, col_;
    elemType data_;
public:
    matElem(int i, int j, elemType data): row_(i), col_(j), data_(data) {}
    int row() const {
        return row_;
    }
    int col() const {
        return col_;
    }
    elemType& data() {
        return data_;
    }
};

template <class elemType>
bool operator==(const matElem<elemType>& a, const matElem<elemType>& b) {
    return a.row_ == b.row_ && a.col_ == b.col_ && a.data_ == b.data_;
}


matElem<int> getRandom(int i_m, int i_n) {
    int i = rand() % i_m;
    int j = rand() % i_n;
    static int d = 10000;

    d++;

    return matElem<int>(i, j, d);
}
