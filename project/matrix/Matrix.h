#pragma once
#include <fstream>
#include <iostream>
using namespace std;

class Invalid_Calculation {};
class Invalid_File {};

template <class T>
class Matrix;

// 友元声明
// 输入输出流
template <class T>
ostream &operator<<(ostream &os, const Matrix<T> &mat);
template <class T>
istream &operator>>(istream &is, Matrix<T> &mat);
// 矩阵element-wise加减乘除运算
template <class T>
Matrix<T> operator+(const Matrix<T> A, const Matrix<T> B);
template <class T>
Matrix<T> operator-(const Matrix<T> A, const Matrix<T> B);
template <class T>
Matrix<T> operator*(const Matrix<T> A, const Matrix<T> B);
template <class T>
Matrix<T> operator/(const Matrix<T> A, const Matrix<T> B);
// 矩阵与字面值加减乘除运算
template <class T>
Matrix<T> operator+(const T num, const Matrix<T> mat);
template <class T>
Matrix<T> operator-(const T num, const Matrix<T> mat);
template <class T>
Matrix<T> operator*(const T num, const Matrix<T> mat);
template <class T>
Matrix<T> operator/(const T num, const Matrix<T> mat);
template <class T>
Matrix<T> operator+(const Matrix<T> mat, const T num);
template <class T>
Matrix<T> operator-(const Matrix<T> mat, const T num);
template <class T>
Matrix<T> operator*(const Matrix<T> mat, const T num);
template <class T>
Matrix<T> operator/(const Matrix<T> mat, const T num);
// 矩阵乘法
template <class T>
Matrix<T> multi(const Matrix<T> A, const Matrix<T> B);

template <class T>
class Matrix {
  // 友元声明
  // 输入输出流
  friend ostream &operator<<<>(ostream &os, const Matrix<T> &mat);
  friend istream &operator>><>(istream &is, Matrix<T> &mat);
  // 矩阵element-wise加减乘除运算
  friend Matrix<T> operator+<>(const Matrix<T> A, const Matrix<T> B);
  friend Matrix<T> operator-<>(const Matrix<T> A, const Matrix<T> B);
  friend Matrix<T> operator*<>(const Matrix<T> A, const Matrix<T> B);
  friend Matrix<T> operator/<>(const Matrix<T> A, const Matrix<T> B);
  // 矩阵与字面值加减乘除运算
  friend Matrix<T> operator+<>(const T num, const Matrix<T> mat);
  friend Matrix<T> operator-<>(const T num, const Matrix<T> mat);
  friend Matrix<T> operator*<>(const T num, const Matrix<T> mat);
  friend Matrix<T> operator/<>(const T num, const Matrix<T> mat);
  friend Matrix<T> operator+<>(const Matrix<T> mat, const T num);
  friend Matrix<T> operator-<>(const Matrix<T> mat, const T num);
  friend Matrix<T> operator*<>(const Matrix<T> mat, const T num);
  friend Matrix<T> operator/<>(const Matrix<T> mat, const T num);
  // 矩阵乘法
  friend Matrix<T> multi<>(const Matrix<T> A, const Matrix<T> B);

 private:
  size_t m, n;  // 表示矩阵的行和列
  T **ptr;      // 指向数据
 public:
  Matrix(size_t rows, size_t cols, T **data) : m(rows), n(cols) {
    ptr = new T *[m];
    for (size_t i = 0; i < m; ++i) {
      ptr[i] = new T[n];
      for (size_t j = 0; j < n; ++j) {
        ptr[i][j] = data[i][j];
      }
    }
  }
  Matrix(size_t rows, size_t cols) : m(rows), n(cols) {
    ptr = new T *[m];
    for (size_t i = 0; i < m; ++i) {
      ptr[i] = new T[n];
    }
  }
  Matrix() : m(0), n(0), ptr(NULL) {}
  Matrix(const Matrix &mat) {
    m = mat.m;
    n = mat.n;
    ptr = new T *[m];
    for (size_t i = 0; i < m; ++i) {
      ptr[i] = new T[n];
      for (size_t j = 0; j < n; ++j) {
        ptr[i][j] = mat.ptr[i][j];
      }
    }
  }
  ~Matrix() {
    for (size_t i = 0; i < m; ++i) {
      delete[] ptr[i];
    }
    delete[] ptr;
  }
  Matrix & operator=(const Matrix &mat) {
    // 清除原有数据
    for (size_t i = 0; i < m; ++i) {
      delete[] ptr[i];
    }
    delete[] ptr;
    // 存入新的数据
    m = mat.m;
    n = mat.n;
    ptr = new T *[m];
    for (size_t i = 0; i < m; ++i) {
      ptr[i] = new T[n];
      for (size_t j = 0; j < n; ++j) {
        ptr[i][j] = mat.ptr[i][j];
      }
    }
    return *this;
  }
  T *operator[](const size_t r) const { return ptr[r]; }
  void input() {
    // 清除原数据
    for (size_t i = 0; i < m; ++i) {
      delete[] ptr[i];
    }
    delete[] ptr;

    // 输入矩阵规模
    do {
      cin.clear();
      rewind(stdin);
      cout << "Please input the numbers of the rows and columns: ";
      cin >> m >> n;
    } while (m <= 0 || n <= 0);

    // 建立二维数组
    ptr = new T *[m];
    for (size_t i = 0; i < m; ++i) {
      ptr[i] = new T[n];
    }

    cin.clear();
    rewind(stdin);
    cout << "Please input the Matrix: " << endl;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        cin >> ptr[i][j];
      }
      cin.clear();
      rewind(stdin);
    }

    cout << "Your Matrix: " << endl;
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        cout << ptr[i][j] << "\t";
      }
      cout << endl;
    }
  }
  void dump(const char *filename) {
    ofstream fout(filename);
    if (!fout) {
      throw Invalid_File();
    }
    fout << m << '\t' << n << '\t';
    for (size_t i = 0; i < m; ++i) {
      for (size_t j = 0; j < n; ++j) {
        fout << ptr[i][j] << '\t';
      }
    }
  }

  T det() {
    if (m == n && m <= 3) {
      return Determinant(ptr, m);
    } else {
      throw Invalid_Calculation();
    }
  }

 private:
  T Determinant(T **det, int scale) {
    // 计算行列式
    if (scale == 1) return det[0][0];

    int i = 0, j = 0, k = 0, sgn = 1;
    T ret = 0;
    T **Cof;

    for (j = 0; j < scale; ++j) {
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
  T **Cofactor(T **det, int scale, int s, int t) {
    // 计算代数余子式
    int i, j;

    T **Cof = new T *[scale - 1];
    for (i = 0; i < scale - 1; ++i) {
      Cof[i] = new T[scale];
    }

    for (i = 0; i < s; ++i) {
      for (j = 0; j < t; ++j) {
        Cof[i][j] = det[i][j];
      }
      for (j++; j < scale; ++j) {
        Cof[i][j - 1] = det[i][j];
      }
    }
    for (i++; i < scale; ++i) {
      for (j = 0; j < t; ++j) {
        Cof[i - 1][j] = det[i][j];
      }
      for (j++; j < scale; ++j) {
        Cof[i - 1][j - 1] = det[i][j];
      }
    }

    return Cof;
  }
};

template <class T>
ostream &operator<<(ostream &os, const Matrix<T> &mat) {
  char sep = '\t';
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      os << mat[i][j] << sep;
    }
    os << endl;
  }
  return os;
}

template <class T>
istream &operator>>(istream &is, Matrix<T> &mat) {
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      is >> mat[i][j];
    }
  }
  return is;
}

Matrix<float> load_f(const char *filePath) {
  ifstream fin(filePath);
  if (!fin) {
    throw Invalid_File();
  }
  size_t m, n;
  fin >> m >> n;
  Matrix<float> mat(m, n);
  fin >> mat;
  return mat;
}

Matrix<int> load_i(const char *filePath) {
  ifstream fin(filePath);
  if (!fin) {
    throw Invalid_File();
  }
  size_t m, n;
  fin >> m >> n;
  Matrix<int> mat(m, n);
  fin >> mat;
  return mat;
}

/************************************************************/

template <class T>
Matrix<T> operator+(const Matrix<T> A, Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret(A.m, B.n);
    for (size_t i = 0; i < A.m; ++i) {
      for (size_t j = 0; j < A.n; ++j) {
        ret.ptr[i][j] = A.ptr[i][j] + B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> operator-(const Matrix<T> A, const Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret(A.m, B.n);
    for (size_t i = 0; i < A.m; ++i) {
      for (size_t j = 0; j < A.n; ++j) {
        ret.ptr[i][j] = A.ptr[i][j] - B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> operator*(const Matrix<T> A, const Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret(A.m, B.n);
    for (size_t i = 0; i < A.m; ++i) {
      for (size_t j = 0; j < A.n; ++j) {
        ret.ptr[i][j] = A.ptr[i][j] * B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> operator/(const Matrix<T> A, const Matrix<T> B) {
  if (A.m == B.m && A.n == B.n) {
    Matrix<T> ret(A.m, B.n);
    for (size_t i = 0; i < A.m; ++i) {
      for (size_t j = 0; j < A.n; ++j) {
        ret.ptr[i][j] = A.ptr[i][j] / B.ptr[i][j];
      }
    }
    return ret;
  } else {
    throw Invalid_Calculation();
  }
}

template <class T>
Matrix<T> operator+(const T num, const Matrix<T> mat) {
  Matrix<T> ret(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      ret.ptr[i][j] = mat.ptr[i][j] + num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> operator-(const T num, const Matrix<T> mat) {
  Matrix<T> ret(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      ret.ptr[i][j] = mat.ptr[i][j] - num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> operator*(const T num, const Matrix<T> mat) {
  Matrix<T> ret(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      ret.ptr[i][j] = mat.ptr[i][j] * num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> operator/(const T num, const Matrix<T> mat) {
  Matrix<T> ret(mat.m, mat.n);
  for (size_t i = 0; i < mat.m; ++i) {
    for (size_t j = 0; j < mat.n; ++j) {
      ret.ptr[i][j] = mat.ptr[i][j] / num;
    }
  }
  return ret;
}

template <class T>
Matrix<T> operator+(const Matrix<T> mat, const T num) {
  return num + mat;
}
template <class T>
Matrix<T> operator-(const Matrix<T> mat, const T num) {
  return num - mat;
}
template <class T>
Matrix<T> operator*(const Matrix<T> mat, const T num) {
  return num * mat;
}
template <class T>
Matrix<T> operator/(const Matrix<T> mat, const T num) {
  return num / mat;
}

template <class T>
Matrix<T> multi(const Matrix<T> A, const Matrix<T> B) {
  if (A.n == B.m) {
    Matrix<T> ret(A.m, B.n);
    for (size_t i = 0; i < A.m; ++i) {
      for (size_t j = 0; j < B.n; ++j) {
        ret.ptr[i][j] = 0;
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
