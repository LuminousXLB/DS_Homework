#pragma once
#include "adjMatrixGraph.h"

template <class TypeOfVer, class TypeOfEdge>
class adjMatrixGraph : public graph<TypeOfEdge> {
 public:
  adjMatrixGraph(int vSize, const TypeOfVer d[], TypeOfEdge noEdgeFlag);
  bool insert(int u, int v, TypeOfEdge w);  //插入权值为w的边
  bool remove(int u, int v);                //删除边
  bool exist(int u, int v) const;           //边是否存在
  ~adjMatrixGraph();

 private:
  TypeOfEdge **edge;  //存放邻接矩阵
  TypeOfVer *ver;     //存放节点值
  TypeOfEdge noEdge;  //邻接矩阵中∞的表示值
};

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::adjMatrixGraph(
    int vSize, const TypeOfVer d[],
    TypeOfEdge noEdgeFlag) {  //构造一个只有顶点没有边的图
  int i, j;
  Vers = vSize;  //初始化节点数
  Edges = 0;     //边数为0
  noEdge = noEdgeFlag;

  //初始化存放结点的数组
  ver = new TypeOfVer[vSize];
  for (i = 0; i < vSize; ++i) ver[i] = d[i];  //节点号赋值

  //邻接矩阵初始化，所有元素为noedge
  edge = new TypeOfEdge *[vSize];  //第一维的空间申请
  for (i = 0; i < vSize; ++i) {
    edge[i] = new TypeOfEdge[vSize];  // edge的每一行是数组
    for (j = 0; j < vSize; ++j) edge[i][j] = noEdge;  //初始化为无边
    edge[i][i] = 0;
  }
}

template <class TypeOfVer, class TypeOfEdge>
adjMatrixGraph<TypeOfVer, TypeOfEdge>::~adjMatrixGraph() {
  delete[] ver;
  for (int i = 0; i < Vers; ++i) delete[] edge[i];
  delete[] edge;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::insert(
    int u, int v, TypeOfEdge w) {  //假定图无重边
  if (u < 0 || u > Vers - 1 || v < 0 || v > Vers - 1)
    return false;  //输入顶点取值范围不合法，退出
  if (edge[u][v] != noEdge) return false;  //若从u到v有边，退出
  edge[u][v] = w;                          //插入边
  ++Edges;                                 //边数加1
  return true;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::remove(int u, int v) {
  if (u < 0 || u > Vers - 1 || v < 0 || v > Vers - 1) return false;
  if (edge[u][v] == noEdge) return false;  //若从u到v无边，退出
  edge[u][v] = noEdge;                     //删除u到v的边
  --Edges;                                 //边数减1
  return true;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjMatrixGraph<TypeOfVer, TypeOfEdge>::exist(int u, int v) const {
  if (u < 0 || u > Vers - 1 || v < 0 || v > Vers - 1) return false;
  if (edge[u][v] == noEdge)
    return false;
  else
    return true;
}
