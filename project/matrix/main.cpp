/*****************************************************************************
 * Matrix 工具集
 * 实现的功能及声名（或调用示例
 * - 构造Matrix
 *   - 默认构造函数：默认的矩阵规模为0*0
 *   - 指定矩阵的行数和列数
 *     `Matrix(size_t rows, size_t cols)`
 *   - 指定矩阵的行数和列数，并提供一个数据集
 *     `Matrix(size_t rows, size_t cols, T **data)`
 * - 键盘输入构造一个矩阵
 *   ```cpp
 *    Matrix<int> A;
 *    A.input();
 *   ```
 * - 实现了赋值运算符重载
 * - 矩阵的基本运算
 *   - 矩阵element-wise加减乘除
 *     `A - B`
 *   - 矩阵与字面量的加减乘除
 *     `A + 1` or `2 * A`
 *   - 矩阵乘法
 *     `Matrix<T> multi(const Matrix<T> A, const Matrix<T> B)`
 *   - 求行列式
 *     `A.det()`
 * - 将矩阵保存到文件和从文件中恢复，支持`<int>`和`<float>`
 *   - 保存到文件
 *     `A.dump("sample_filename")`
 *   - 从文件中恢复
 *     `Matrix<float> load_f(const char *filePath)` // for <int>
 *     `Matrix<int> load_i(const char *filePath)`   // for <float>
 *****************************************************************************/

#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
  Matrix<int> A = load_i("A.data");
  // A.input();
  // A.dump("A.data");

  Matrix<int> B = load_i("B.data");
  // B.input();
  // B.dump("B.data");

  cout << endl;

  cout << A << endl;
  cout << B << endl;

  cout << A - B << endl;
  cout << endl;

  cout << A + 1 << endl;

  cout << multi(A, B) << endl;

  cout << A.det() << endl;

  cout << (B = A) << endl;

  return 0;
}