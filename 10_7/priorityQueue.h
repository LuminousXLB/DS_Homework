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
    comp_ = comp;
  }
  ~priorityQueue() {}
  bool empty() { return que_.size() < 2; }
  size_t size() { return que_.size() - 1; }
  T top() { return que_[1]; }
  bool push(const T& x) {
    que_.push_back(x);

    size_t ikid = que_.size() - 1;
    while (que_[ikid] < que_[ikid / 2]) {
      que_[ikid] = que_[ikid / 2];
      que_[ikid / 2] = x;
      ikid /= 2;
    }
  }
  void pop() {
    // TODO: POP
    precolateDown(1);
  }

 private:
  void precolateDown(int hole) {
    size_t kid = que_[2 * hole] < que_[2 * hole + 1] ? 2 * hole : 2 * hole + 1;
    que_[hole] = que_[kid];
    precolateDown(kid);
  }
};

// 二叉堆是完全二叉树
// 二叉树的高度k = log_2{n} +1