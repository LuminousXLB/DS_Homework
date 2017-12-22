#pragma once

template <class TypeOfEdge>
class graph {
 public:
  virtual bool insert(int u, int v, TypeOfEdge w) = 0;  //插入边
  virtual bool remove(int u, int v) = 0;                //删除边
  virtual bool exist(int u, int v) const = 0;           //边是否存在
  virtual numOfVer() const { return Vers; }
  virtual numOfEdge() const { return Edges; }

 protected:
  int Vers, Edges;
};
