#include "Matrix.h"
#include <iostream>

using namespace std;

template <typename T>
Matrix<T> init_matrix(size_t m, size_t n, T** ptr) {
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

  T** mat = new T*[m];
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
    cout << "Please input the numbers of the rows and columns: ";
    cin >> m >> n;
  } while (m > 0 && n > 0);

  // 建立二维数组
  T** mat = new T*[m];
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
    // cin.clear();	rewind(stdin);
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