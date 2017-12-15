#pragma once
#include <iostream>

using namespace std;

class Invalid_Calculation {};

template <class T>
struct Matrix {
  size_t m, n;  // 表示矩阵的行和列
  T **ptr;      // 指向数据
  // ~Matrix() {
  //   for (size_t i = 0; i < m; i++) {
  //     delete[] ptr[i];
  //   }
  //   delete[] ptr;
  // }
};

template <class T>
Matrix<T> init_matrix(size_t m, size_t n, T **ptr);

template <class T>
Matrix<T> empty_matrix(size_t m, size_t n);

template <class T>
Matrix<T> input_matrix();

template <class T>
void del_matrix(Matrix<T> mat);

template <class T>
void printMatrix(Matrix<T> mat);

template <class T>
Matrix<T> elementAdd(Matrix<T> A, Matrix<T> B);

template <class T>
Matrix<T> elementSub(Matrix<T> A, Matrix<T> B);

template <class T>
Matrix<T> elementMul(Matrix<T> A, Matrix<T> B);

template <class T>
Matrix<T> elementDiv(Matrix<T> A, Matrix<T> B);

template <class T>
Matrix<T> numAdd(T num, Matrix<T> mat);

template <class T>
Matrix<T> numSub(T num, Matrix<T> mat);

template <class T>
Matrix<T> numMul(T num, Matrix<T> mat);

template <class T>
Matrix<T> numDiv(T num, Matrix<T> mat);

template <class T>
Matrix<T> mul(Matrix<T> A, Matrix<T> B);

template <class T>
T getValue(Matrix<T> mat);

template <class T>
T Determinant(T **det, int scale);

template <class T>
T **Cofactor(T **det, int scale, int s, int t);

/************************************************************/
// Implementation
template <class T>
Matrix<T> init_matrix(size_t m, size_t n, T **ptr) {
  Matrix<T> tmp;
  tmp.m = m;
  tmp.n = n;
  tmp.ptr = ptr;
  return tmp;
}

template <class T>
Matrix<T> empty_matrix(size_t m, size_t n) {
  Matrix<T> tmp;
  tmp.m = m;
  tmp.n = n;

  T **mat = new T *[m];
  for (size_t i = 0; i < m; i++) {
    mat[i] = new T[n];
  }

  tmp.ptr = mat;
  return tmp;
}

template <class T>
Matrix<T> input_matrix() {
  // 输入矩阵规模
  size_t m, n;
  do {
    cin.clear();
    rewind(stdin);
    cout << "Please input the numbers of the rows and columns: ";
    cin >> m >> n;
  } while (m <= 0 || n <= 0);

  // 建立二维数组
  T **mat = new T *[m];
  for (size_t i = 0; i < m; i++) {
    mat[i] = new T[n];
  }

  cin.clear();
  rewind(stdin);
  cout << "Please input the Matrix: " << endl;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
    cin.clear();	rewind(stdin);
  }

  cout << "Your Matrix: " << endl;
  for (size_t i = 0; i < m; i++) {
    for (size_t j = 0; j < n; j++) {
      cout << mat[i][j] << "\t";
    }
    cout << endl;
  }
  return init_matrix<T>(m, n, mat);
}

template <class T>
void del_matrix(Matrix<T> mat) {
  for (size_t i = 0; i < mat.m; i++) {
    delete[] mat.ptr[i];
  }
  delete[] mat.ptr;
}

template <class T>
void printMatrix(Matrix<T> mat) {
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      cout << mat.ptr[i][j] << "\t";
    }
    cout << endl;
  }
}

template <class T>
Matrix<T> elementAdd(Matrix<T> A, Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret = empty_matrix<T>(A.m, B.n);
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
    Matrix<T> ret = empty_matrix<T>(A.m, B.n);
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
    Matrix<T> ret = empty_matrix<T>(A.m, B.n);
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
    Matrix<T> ret = empty_matrix<T>(A.m, B.n);
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
  Matrix<T> ret = empty_matrix<T>(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] + num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> numSub(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix<T>(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] - num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> numMul(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix<T>(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; i++) {
    for (size_t j = 0; j < mat.n; j++) {
      ret.ptr[i][j] = mat.ptr[i][j] * num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> numDiv(T num, Matrix<T> mat) {
  Matrix<T> ret = empty_matrix<T>(mat.m, mat.n);
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
    Matrix<T> ret = empty_matrix<T>(A.m, B.n);
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

template <class T>
T Determinant(T **det, int scale) {
  if (scale == 1) return det[0][0];

  int i = 0, j = 0, k = 0, sgn = 1;
  T ret = 0;
  T **Cof;

  for (j = 0; j < scale; j++) {
    Cof = Cofactor(det, scale, i, j);
    ret += det[i][j] * sgn * Determinant(Cof, scale - 1);
    sgn *= -1;
    for (k = 0; k < scale - 1; k++) {
      delete[] Cof[k];
    }
    delete[] Cof;
  }
  return ret;
}

template <class T>
T **Cofactor(T **det, int scale, int s, int t) {
  int i, j;

  T **Cof = new T *[scale - 1];
  for (i = 0; i < scale - 1; i++) {
    Cof[i] = new T[scale];
  }

  for (i = 0; i < s; i++) {
    for (j = 0; j < t; j++) {
      Cof[i][j] = det[i][j];
    }
    for (j++; j < scale; j++) {
      Cof[i][j - 1] = det[i][j];
    }
  }
  for (i++; i < scale; i++) {
    for (j = 0; j < t; j++) {
      Cof[i - 1][j] = det[i][j];
    }
    for (j++; j < scale; j++) {
      Cof[i - 1][j - 1] = det[i][j];
    }
  }

  return Cof;
}
