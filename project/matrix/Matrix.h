#pragma once
#include <iostream>

using namespace std;

class Invalid_Calculation {};

template <class T>
struct Matrix {
  size_t m, n;  // 表示矩阵的行和列
  T **ptr;      // 指向数据
  ~Matrix() {
    for (size_t i = 0; i < m; i++) {
      delete[] ptr[i];
    }
    delete[] ptr;
  }
};

// matrix.cpp
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

// calculate.cpp
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

// determinant.cpp
template <class T>
T Determinant(T **det, int scale);

template <class T>
T **Cofactor(T **det, int scale, int s, int t);