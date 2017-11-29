#pragma once
#include "hashTable.h"

template <class Type>
class closeHashTable : public hashTable<Type> {
 private:
  struct node {
    Type data;
    int state;  // 0为空；1为使用状态； 2为延迟删除状态
    node() { state = 0; }  //初始时存储单元为空
  };
  node *array;
  int size;
  int (*key)(const Type &x);
  int activecnt;
  int disabledcnt;
  int dissup;
  void watchdog() {  // 检查是否满足rehash条件
    double lf = activecnt / double(size);
    if (lf >= 0.5 || disabledcnt >= dissup) {
      rehash(activecnt * 2);
    }
  }

 public:
  closeHashTable(int length = 101, int disableSup = 50,
                 int (*f)(const Type &x) = hashTable<Type>::defaultKey);
  ~closeHashTable() { delete[] array; }
  bool find(const Type &x) const;
  bool insert(const Type &x);
  bool remove(const Type &x);
  void rehash(int newsize = -1);  //整理散列表，真正删除标记元素
};

template <class Type>
closeHashTable<Type>::closeHashTable(int length, int disableSup,
                                     int (*f)(const Type &x)) {
  size = length;           //散列表初始长度
  array = new node[size];  //申请散列表空间
  key = f;                 //从基类继承键值
  activecnt = 0;           // 计数器初始化
  disabledcnt = 0;         // 计数器初始化
  dissup = disableSup;     // 删除重散列阈值
}

template <class Type>
bool closeHashTable<Type>::insert(const Type &x) {
  int initPos, pos;
  initPos = pos = key(x) % size;  //计算待插入元素的散列地址
  do {
    if (array[pos].state != 1) {  //插入单元为空或者已删除
      array[pos].data = x;        //给单元赋值
      if (array[pos].state == 2) --disabledcnt;  // 2->1 cnt--
      array[pos].state = 1;                      //更改单元属性
      ++activecnt;                               // insert cnt++
      watchdog();
      return true;
    }  //插入成功
    if (array[pos].state == 1 && array[pos].data == x) return false;
    //若pos位置已经存在x且是正常元素，插入失败
    pos = (pos + 1) % size;  //执行线性探测(已被非x的键值占用)
  } while (pos != initPos);  // pos和initPos重合预示线性探测失败
  return false;
}

template <class Type>
bool closeHashTable<Type>::remove(const Type &x) {
  int initPos, pos;
  initPos = pos = key(x) % size;  //计算待删除元素的散列地址
  do {
    if (array[pos].state == 0) return false;  //指定位置为空，失败
    //指定位置为x，则预删除
    if (array[pos].state == 1 && array[pos].data == x) {
      array[pos].state = 2;
      --activecnt;    // remove cnt--;
      ++disabledcnt;  // remove cnt++;
      watchdog();
      return true;
    }
    pos = (pos + 1) % size;  //否则向前线性探测(已被非x占用或已删除)
  } while (pos != initPos);
  return false;
}

template <class Type>
bool closeHashTable<Type>::find(const Type &x) const {
  int initPos, pos;
  initPos = pos = key(x) % size;  //计算待查找元素的散列地址
  do {
    if (array[pos].state == 0)
      return false;  //如果所查位置为空
                     //所以需要延迟删除
    if (array[pos].state == 1 && array[pos].data == x)
      return true;           //所查位置元素==x，找到
    pos = (pos + 1) % size;  //否则线性探索地往下找
  } while (pos != initPos);
  return false;  // pos和initPos重合预示查找失败
}

template <class Type>
void closeHashTable<Type>::rehash(int newsize) {
  if (newsize < 0) newsize = size;
  int oldsize = size;
  node *tmp = array;
  size = newsize;             // 更新散列表长度
  array = new node[newsize];  //申请新的散列空间
  activecnt = 0;
  disabledcnt = 0;
  for (int i = 0; i < size; ++i) {
    if (tmp[i].state == 1)  //拷贝那些没有预删除的元素到新表
      insert(tmp[i].data);  //注意这里不是直接拷贝，而是用插入
                            //因为仍有可能有冲突
  }
  delete[] tmp;  //删除原表
}
