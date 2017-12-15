// 学生需要选修一定数目的课程才能毕业，这些课程之间有先导关系。
// 假设所有的课程在每学期都能提供给学生选修，学生每学期可以选修的课程数不限。
// 给出一些课程以及课程之间的关系，安排一个计划，用最少的学期数修完所有的课程。

#include <iostream>
#include <string>
#include "adjListGraph.h"
using namespace std;

int main() {
  string courses[] = {"MA080", "MA081", "MA077", "MA256", "PH224",
                      "PH246", "PH114", "PH116", "PH244", "PH245",
                      "PH364", "PH223", "PH302", "PH303"};
  adjListGraph<string, int> graph(14, courses);
  // graph.insert(0,1,)
}
