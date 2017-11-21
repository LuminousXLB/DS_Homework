#pragma once

template <class Type>
class hashTable {
public:
    virtual int find(const Type& x) const = 0;

    // virtual bool find(const Type& x) const = 0;
    virtual bool insert(const Type& x) = 0;
    virtual bool remove(const Type& x) = 0;

protected:
    int (*key)(const Type& x);   //取出元素x的值，并转换成整型
    static int defaultKey(const int& k) {
        //如果输入的Key原本就是整形，使用缺省转换函数
        return k;
    }
};
