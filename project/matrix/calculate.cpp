#include "Matrix.h"

template <class T>
Matrix<T> elementAdd(Matrix<T> A, Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret = empty_matrix(A.m, B.n);
    for (size_t i = 0; i < A.m; i++) {
      for (size_t j = 0; j < A.n; j++) {
        ret.ptr[i][j] = A.ptr[i][j] + B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> elementSub(Matrix<T> A, Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret = empty_matrix(A.m, B.n);
    for (size_t i = 0; i < A.m; i++) {
      for (size_t j = 0; j < A.n; j++) {
        ret.ptr[i][j] = A.ptr[i][j] - B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> elementMul(Matrix<T> A, Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret = empty_matrix(A.m, B.n);
    for (size_t i = 0; i < A.m; i++) {
      for (size_t j = 0; j < A.n; j++) {
        ret.ptr[i][j] = A.ptr[i][j] * B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> elementDiv(Matrix<T> A, Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret = empty_matrix(A.m, B.n);
    for (size_t i = 0; i < A.m; i++) {
      for (size_t j = 0; j < A.n; j++) {
        ret.ptr[i][j] = A.ptr[i][j] / B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> numAdd(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] + num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> numSub(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] - num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> numMul(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] * num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> numDiv(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] / num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> mul(Matrix<T> A, Matrix<T> B) {
  if (A.n == B.m) {
    Matrix<T> ret = empty_matrix(A.m, B.n);
    for (size_t i = 0; i < A.m; i++) {
      for (size_t j = 0; j < B.n; j++) {
        for (size_t k = 0; k < A.n; k++) {
          ret.ptr[i][j] += A.ptr[i][k] * B.ptr[k][j];
        }
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
T getValue(Matrix<T> mat) {
  if (mat.m == mat.n && mat.m <= 3) {
    return Determinant(mat.ptr, mat.m);
  } else {
    throw Invalid_Calculation();
  }
}
