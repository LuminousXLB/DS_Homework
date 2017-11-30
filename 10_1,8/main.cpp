#include <iostream>

using namespace std;

template <class T>
bool defaultcomp(const T& a, const T& b) {
  return a < b;
}

template <class T>
void quicksort(T arr[], size_t len,
               bool (*comp)(const T& a, const T& b) = defaultcomp) {
  if (len > 1) {
    // find standard elements
    size_t si[3] = {0, len / 2, len - 1};  // sample index
    // Sort sample array
    if (arr[si[1]] < arr[si[0]]) {
      size_t tmp = si[1];
      si[1] = si[0];
      si[0] = tmp;
    }
    if (arr[si[1]] > arr[si[2]]) {
      size_t tmp = si[1];
      si[1] = si[2];
      si[2] = tmp;
    }
    // Organize array to fit origin implementation
    T std = arr[si[1]];
    arr[si[1]] = arr[0];
    arr[0] = std;
    // Quick sort
    size_t il = 0, ir = len - 1;
    while (il != ir) {
      while (il < ir && !comp(arr[ir], std) /* arr[ir] >= std */) {
        --ir;
      }
      if (il < ir) {
        arr[il] = arr[ir];
      }
      while (il < ir && !comp(std, arr[il]) /* arr[il] <= std */) {
        ++il;
      }
      if (il < ir) {
        arr[ir] = arr[il];
      }
    }
    arr[il] = std;
    // Recursion
    quicksort(arr, il, comp);
    quicksort(arr + il + 1, len - il - 1, comp);
  }
}

template <class T>
int duplicateRemoval(T seq[], int n) {
  // 对一个已排序的数组去重算法
  int i = 1, step = 1;

  for (i = 1; i < n; i++) {
    if (seq[i] == seq[i - step]) {
      step++;
    } else {
      seq[i - step + 1] = seq[i];
    }
  }
  n -= --step;
  return n;
}

int main() {
  int a[] = {20, 16, 30, 5,  18, 25, 35, 18, 25, 35,
             8,  32, 40, 12, 37, 10, 39, 38, 45, 43};

  cout << "origin array: \n\t";
  for (int x : a) cout << x << " ";
  cout << endl;

  cout << "sorted array: \n\t";
  quicksort(a, 20);
  for (int x : a) cout << x << " ";
  cout << endl;

  cout << "duplicate removed: \n\t";
  int n = duplicateRemoval(a, 20);
  for (int i = 0; i < n; ++i) {
    cout << a[i] << " ";
  }
  cout << endl;

  cout << "size of the array: " << n << endl;
  return 0;
}
