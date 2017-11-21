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
    int probe(int pos, int i = 0) const {
        return (pos + 2 * i - 1) % size;
    }
public:
    closeHashTable(int length = 101, int (*f)(const Type &x) = hashTable<Type>::defaultKey);
    ~closeHashTable() {
        delete [] array;
    }
    int getsize() const {
        return size;
    }
    int find(const Type& x) const;

    // bool find(const Type& x) const;
    bool insert(const Type& x);
    bool remove(const Type& x);
    void rehash(int s = 0);
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

    // static int conflict_cnt = 0;        // 冲突计数器
    // static int success_cnt = 0;
    int cnt = 0;

    initPos = pos = key(x) % size;
    do {
        if (array[pos].state != 1) {
            array[pos].data = x;
            array[pos].state = 1;
            // success_cnt++;
            // cout << "[SUCCESS] #" << success_cnt
            //      << "\t key = " << key(x)
            //      << "\t initPos = " << initPos
            //      << "\t pos = " << pos << endl;

            return true;
        } else if (array[pos].data == x) {
            return false;
        } else {
            // conflict_cnt++;
            // cout << "[CONFLICT] #" << conflict_cnt
            //      << "\t key = " << key(x)
            //      << "\t initPos = " << initPos
            //      << "\t pos = " << pos;
            cnt++;
            pos = probe(pos, cnt);
            // cout << "\t nextpos = " << pos << endl;
        }
    } while (pos != initPos);
    return false;
}


template <class Type>
bool closeHashTable<Type>::remove(const Type& x) {
    int initPos, pos;
    int cnt = 0;

    initPos = pos = key(x) % size; //计算待删除元素的散列地址
    do {
        cnt++;
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
        } else {
            pos = probe(pos, cnt);
        }
    } while (pos != initPos);
    return false;
}


// template <class Type>
// bool closeHashTable<Type>::find(const Type& x) const {
//     int initPos, pos;
//     bool ret = false;
//     static int cnt = 0;
//
//     initPos = pos = key(x) % size;
//     do {
//         cnt++;
//         if (array[pos].state == 0) {
//             ret = false;
//             break;
//         } else if ((array[pos].state == 1) && (array[pos].data == x)) {
//             ret = true;
//             break;
//         }
//         pos = probe(pos, cnt);
//     } while (pos != initPos);
//
//     cout << cnt << endl;
//     return ret;
// }
template <class Type>
int closeHashTable<Type>::find(const Type& x) const {
    int initPos, pos;
    bool found = false;
    int cnt = 0;

    initPos = pos = key(x) % size;
    do {
        cnt++;
        if (array[pos].state == 0) {
            found = false;
            break;
        } else if ((array[pos].state == 1) && (array[pos].data == x)) {
            found = true;
            break;
        }
        pos = probe(pos, cnt);
    } while (pos != initPos);

    // cout << cnt << endl;
    return cnt;
}


template <class Type>
void closeHashTable<Type>::rehash(int s) {
    node *tmp = array;

    if (s) {
        size = s;
    }
    array = new node[size];
    for (int i = 0; i < size; ++i) {
        if (tmp[i].state == 1) {
            insert(tmp[i].data);
        }
    }
    delete [] tmp;
}
