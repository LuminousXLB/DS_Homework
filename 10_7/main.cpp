#include <iostream>
#include "priorityQueue.h"
using namespace std;

class InvalidRank {};
template <class T>
void percolateDown(T que_[], size_t size, size_t hole);

template <class T>
T findkMAX_O_N_klogN(T arr[], size_t len, size_t k) {
  if (k > len) throw InvalidRank();
  priorityQueue<int> que(arr, len, [](const T& a, const T& b) -> bool {
    return a > b;
  });  // 建立二叉堆O(N)
  T ret;
  for (size_t i = 0; i < k; ++i) {
    ret = que.top();  // k次出队O(klogN)
    que.pop();
    // cout << ret << endl;
  }
  return ret;  // O(N+klogN)
}

template <class T>
T findkMAX_O_Nlogk(T arr[], size_t len, size_t k) {
  if (k > len) throw InvalidRank();
  T* heap = new T[k + 1];
  // 构造一个有k个元素的最小化堆，O(k)
  // top的值为k个元素中最小，即第k大
  for (size_t i = 0; i < k; ++i) {
    heap[i + 1] = arr[i];
  }
  for (size_t i = k / 2; i > 0; --i) {
    percolateDown(heap, k + 1, i);
  }
  // 遍历剩下的元素，[O(N-k), O((N-k)logk)]
  for (size_t i = k; i < len; i++) {
    if (arr[i] > heap[1]) {
      // 若当前元素大于top，则存在不止k-1个元素比top大
      // 用当前元素把top替换掉，执行向下过滤，使最小的元素浮上来
      heap[1] = arr[i];
      percolateDown(heap, k + 1, 1);
    }
  }
  // 全部处理结束，堆的top即为arr中第k大的元素
  T ret = heap[1];
  delete[] heap;
  return ret;
}

int main() {
  int a[] = {20, 16, 30, 5,  18, 25, 35, 18, 25, 35,
             8,  32, 40, 12, 37, 10, 39, 38, 45, 43};
  cout << findkMAX_O_N_klogN(a, sizeof a / sizeof a[0], 4) << endl;
  cout << findkMAX_O_Nlogk(a, sizeof a / sizeof a[0], 4) << endl;
  return 0;
}

template <class T>
void percolateDown(T que_[], size_t size, size_t hole) {
  T tmp = que_[hole];
  size_t child = hole * 2;

  while (child < size) {
    if (child < size - 1 && que_[child + 1] < que_[child]) {
      child++;
    }
    if (que_[child] < tmp) {
      que_[hole] = que_[child];
    } else {
      break;
    }
    hole = child;
    child *= 2;
  }
  que_[hole] = tmp;
}