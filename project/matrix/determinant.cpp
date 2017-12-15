#include "Matrix.h"

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
