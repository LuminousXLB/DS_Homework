#include <iostream>
#include <cstdlib>
#include <ctime>
#include "closeHashTable.h"
#include "matElem.h"
#include "utils.h"

using namespace std;

/******************** params **************************************************/

// 数组规模
const int _Matrix_Rows_ = 100;
const int _Matrix_Columns_ = 100;

// 数据密度
const double _Matrix_Duty_ = 0.01;

// 散列表负载因子
const double _Load_Factor_ = 0.50;

/******************** functions declaration ***********************************/

// 计算哈希表的规模
int tableSize(const int mr, const int mc, const double md, const double lf);
int tableSize(int origin, const double lf);

// 哈希函数
template <class elemType>
int matelem2key(const matElem<elemType>& elem);

/******************** main ****************************************************/

int main(int argc, char const *argv[]) {
    // 设定随机数种子
    srand(time(NULL));

    double avg = 0;
    int loop = 1000;
    for (size_t i = 0; i < loop; i++) {
        // 初始化散列表
        // int size = 314;

        int size = tableSize(_Matrix_Rows_, _Matrix_Columns_, _Matrix_Duty_, _Load_Factor_);
        int elemcnt = 0;
        closeHashTable<matElem<int>> ht(size, matelem2key);
        // if (i == 0) {
        //     cout << "SIZE\t" << size << endl;
        // }

        // 生成随机元素并加入散列表
        for (int i = 0; i < 100; i++) {
            for (int j = 0; j < 100; j++) {
                int prob = rand() % 100;
                if (prob == 1) {
                    ht.insert(matElem<int>(i, j, 10));
                    elemcnt++;
                }
            }
        }

        ht.rehash(tableSize(elemcnt, _Load_Factor_));

        // cout << "Create End" << endl;
        // cout << "SIZE\t" << ht.getsize();

        int find_cnt = 0;
        // for (int i = 0; i < 10000; ++i) {
        //     matElem<int> tmp = getRandom(_Matrix_Rows_, _Matrix_Columns_);
        //     // cout << i << '\t' << rec[tmp.row()][tmp.col()] << endl;
        //     find_cnt += ht.find(tmp);
        //     // cout << find_cnt << endl;
        // }
        for (int i = 0; i < 100; ++i) {
            for (int j = 0; j < 100; ++j) {
                matElem<int> tmp(i, j, 10);
                find_cnt += ht.find(tmp);
            }
        }
        double rate = find_cnt / 10000.00;
        if (rate < 1.7) {
            cout << rate << endl;
        }
        avg += rate;
    }
    cout << "avg\t" << avg / loop << endl;

    return 0;
}


/******************** function implementation *********************************/

// 计算哈希表的规模
int tableSize(const int mr, const int mc, const double md, const double lf) {
    // 计算有效值个数并保证负载因子不超过lf
    int si = mr * mc * md / lf;

    // 寻找不小于（保证lf）上述结果的最小素数
    si += !(si % 2);
    while (!isPrime(si)) {
        si += 2;
    }

    return si;
}


int tableSize(int origin, const double lf) {
    origin = origin / lf;

    origin += !(origin % 2);
    while (!isPrime(origin)) {
        origin += 2;
    }

    return origin;
}


// 哈希函数
template <class elemType>
int matelem2key(const matElem<elemType>& elem) {
    // int hash = elem.row() * 100 + elem.col(); // 2.05588

    // int hash = elem.col() * 100 + elem.row();

    int hash = elem.row() * 3 + elem.col() / 33; // 2.57826

    // int hash = 0;
    // int r = elem.row();
    // int c = elem.col();
    //
    // // double rate = 211.0 / 81;
    //
    // do {
    //     // hash = hash * 100 + (r % 10) * (c % 10);
    //     hash = hash * 3 + (r % 11) * (c % 11);
    //     // hash = hash + (r % 10) * (c % 10) * rate;
    //     r /= 10;
    //     c /= 10;
    // } while (r > 0 || c > 0);


    // int hash1 = elem.row() * 100 + elem.col();
    // int hash2 = elem.col() * 100 + elem.row();
    // int hash = (hash1 * hash2) % (hash1 + hash2);

    // int hash = elem.row() * elem.row() + elem.col() * elem.col();

    return hash;
}
