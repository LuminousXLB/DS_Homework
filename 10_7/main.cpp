#include <iostream>
#include <vector>
#include <queue>
#include "priorityQueue.h"
using namespace std;

int main() {
  // vector<int> vec(19);
  // cout << vec.size() << endl;
  // cout << vec.capacity() << endl;
  // priority_queue<int> que;
  priorityQueue<int> que;
  int arr[] = {2, 4, 7, 8, 6, 4, 3, 6, 3, 2};
  for(int &x : arr) {
    que.push(x);
  }
  while(!que.empty()) {
    cout << que.top() << endl;
    que.pop();
  }
  return 0;
}