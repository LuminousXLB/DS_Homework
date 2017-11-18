#pragma once
#include "hashTable.h"
#include <iostream>

using namespace std;

template <class Type>
class closeHashTable: public hashTable<Type> {
private:
    struct node {
        Type data;
        int state; //0-empty, 1-active, 2-deleted
        node() {
            state = 0;
        }
    };
    node *array;
    int size;
    int (*key)(const Type& x);
public:
    closeHashTable(int length = 101, int (*f)(const Type &x) = hashTable<Type>::defaultKey);
    ~closeHashTable() {
        delete [] array;
    }
    bool find(const Type& x) const;
    bool insert(const Type& x);
    bool remove(const Type& x);
    void rehash();
};

template <class Type>
closeHashTable<Type>::closeHashTable(int length, int (*f)(const Type &x)) {
    size = length;
    array = new node[size];
    key = f;
}


template <class Type>
bool closeHashTable<Type>::insert(const Type& x) {
    int initPos, pos;
    static int conflict_cnt = 0;        // 冲突计数器

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state != 1) {
            array[pos].data = x;
            array[pos].state = 1;
            return true;
        } else if ((array[pos].state == 1) && (array[pos].data == x)) {
            return false;
        }
        pos = (pos + 1) % size;
        cout << "[CONFLICT] #" << conflict_cnt
             << "\t key = " << key(x)
             << "\t initPos = " << initPos
             << "\t pos = " << pos << endl;
    } while (pos != initPos);
    return false;
}


template <class Type>
bool closeHashTable<Type>::remove(const Type& x) {
    int initPos, pos;

    initPos = pos = key(x) % size; //计算待删除元素的散列地址
    do {
        if (array[pos].state == 0) {
            //指定位置为空，失败
            return false;
        } else if (array[pos].data == x) {
            // 指定位置为x
            if (array[pos].state == 1) {
                // active, 预删除
                array[pos].state = 2;
                return true;
            } else if (array[pos].state = 2) {
                // deleted，删除失败
                return false;
            }
        }
        pos = (pos + 1) % size; //否则向前线性探测(已被非x占用或已删除)
    } while (pos != initPos);
    return false;
}


template <class Type>
bool closeHashTable<Type>::find(const Type& x) const {
    int initPos, pos;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state == 0) {
            return false;
        } else if ((array[pos].state == 1) && (array[pos].data == x)) {
            return true;
        }
        pos = (pos + 1) % size;
    } while (pos != initPos);
    return false;
}


template <class Type>
void closeHashTable<Type>::rehash() {
    node *tmp = array;

    array = new node[size];
    for (int i = 0; i < size; ++i) {
        if (tmp[i].state == 1) {
            insert(tmp[i].data);
        }
    }
    delete [] tmp;
}
