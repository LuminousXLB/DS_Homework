#pragma once

#include <cstdlib>

template <class elemType>
class matElem;

template <class elemType>
bool operator==(const matElem<elemType>&, const matElem<elemType>&);

template <class elemType>
class matElem {
  friend bool operator==<>(const matElem<elemType>&, const matElem<elemType>&);

 private:
  unsigned row_, col_;
  elemType data_;

 public:
  matElem(unsigned i, unsigned j, elemType data)
      : row_(i), col_(j), data_(data) {}
  matElem() {}
  unsigned row() const { return row_; }
  unsigned col() const { return col_; }
  elemType& data() { return data_; }
};

template <class elemType>
bool operator==(const matElem<elemType>& a, const matElem<elemType>& b) {
  return a.row_ == b.row_ && a.col_ == b.col_;  // && a.data_ == b.data_;
}
