#pragma once
#include <vector>

using namespace std;

template <class T>
class priorityQueue {
  static bool default_comp(const T& a, const T& b) { return a < b; }

 private:
  vector<T> que_;
  bool (*comp_)(const T& a, const T& b);

 public:
  priorityQueue(bool (*comp)(const T& a, const T& b) = default_comp) {
    T randinit;
    que_.push_back(randinit);
    comp_ = comp;
  }
  priorityQueue(T arr[], size_t len,
                bool (*comp)(const T& a, const T& b) = default_comp) {
    T randinit;
    que_.push_back(randinit);
    comp_ = comp;
    for (size_t i = 0; i < len; ++i) {
      que_.push_back(arr[i]);
    }
    for (size_t i = size() / 2; i > 0; --i) {
      percolateDown(i);
    }
  }

  ~priorityQueue() {}

  bool empty() { return que_.size() < 2; }

  size_t size() { return que_.size() - 1; }

  T top() { return que_[1]; }

  bool push(const T& x) {
    que_.push_back(x);
    size_t ikid = que_.size() - 1;
    while (ikid > 1 && comp_(que_[ikid], que_[ikid / 2])) {
      que_[ikid] = que_[ikid / 2];
      que_[ikid / 2] = x;
      ikid /= 2;
    }
  }

  void pop() {
    // TODO: POP
    que_[1] = que_[size()];
    que_.resize(size());
    percolateDown(1);
  }

 private:
  void percolateDown(size_t hole) {
    T tmp = que_[hole];
    size_t child = hole * 2;

    while (child < que_.size()) {
      if (child < size() && comp_(que_[child + 1], que_[child])) {
        child++;
      }
      if (comp_(que_[child], tmp)) {
        que_[hole] = que_[child];
      } else {
        break;
      }
      hole = child;
      child *= 2;
    }
    que_[hole] = tmp;
  }
};

// 二叉堆是完全二叉树
// 二叉树的高度k = log_2{n} +1