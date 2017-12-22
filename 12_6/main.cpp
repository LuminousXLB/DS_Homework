// 学生需要选修一定数目的课程才能毕业，这些课程之间有先导关系。
// 假设所有的课程在每学期都能提供给学生选修，学生每学期可以选修的课程数不限。
// 给出一些课程以及课程之间的关系，安排一个计划，用最少的学期数修完所有的课程。

#include <algorithm>
#include <iostream>
#include <string>
#include "adjListGraph.h"
using namespace std;

const string courses[] = {"MA080", "MA081", "MA077", "MA256", "PH224",
                          "PH246", "PH114", "PH116", "PH244", "PH245",
                          "PH364", "PH223", "PH302", "PH303"};

size_t fi(string target) {
  size_t size = sizeof(courses) / sizeof(courses[0]);
  for (size_t i = 0; i < size; ++i) {
    if (target == courses[i]) return i;
  }
  throw target + string(" Not Found");
  return -1;
}

int main() {
  adjListGraph<string, int> graph(14, courses);

  graph.insert(fi("MA080"), fi("PH114"), 1);
  graph.insert(fi("MA080"), fi("MA077"), 1);
  graph.insert(fi("MA080"), fi("MA081"), 1);
  graph.insert(fi("MA081"), fi("MA256"), 1);
  graph.insert(fi("MA081"), fi("PH223"), 1);
  graph.insert(fi("MA077"), fi("PH114"), 1);
  graph.insert(fi("MA077"), fi("MA256"), 1);
  graph.insert(fi("MA256"), fi("PH116"), 1);
  graph.insert(fi("MA256"), fi("PH224"), 1);
  graph.insert(fi("PH224"), fi("PH244"), 1);
  graph.insert(fi("PH114"), fi("PH116"), 1);
  graph.insert(fi("PH114"), fi("PH223"), 1);
  graph.insert(fi("PH116"), fi("PH244"), 1);
  graph.insert(fi("PH244"), fi("PH245"), 1);
  graph.insert(fi("PH245"), fi("PH364"), 1);
  graph.insert(fi("PH245"), fi("PH303"), 1);
  graph.insert(fi("PH223"), fi("PH302"), 1);
  graph.insert(fi("PH223"), fi("PH303"), 1);
  graph.insert(fi("PH302"), fi("PH303"), 1);

  int cnt = graph.HierarchicalTopology();

  cout << "最少需要" << cnt << "个学期" << endl;

  return 0;
}
