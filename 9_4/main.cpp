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
const double _Matrix_Sparseness_ = 0.01;

// 散列表负载因子
const double _Load_Factor_ = 0.50;

/******************** functions declaration ***********************************/

// 计算哈希表的规模
int tableSize(const int mr, const int mc, const double ms, const double lf);

// 哈希函数
template <class elemType>
int matelem2key(const matElem<elemType>& elem);

/******************** main ****************************************************/

int main(int argc, char const *argv[]) {
    // 设定随机数种子
    srand(time(NULL));

    // 初始化散列表
    int size = tableSize(_Matrix_Rows_, _Matrix_Columns_, _Matrix_Sparseness_, _Load_Factor_);
    closeHashTable<matElem<int>> ht(size, matelem2key);

    cout << size << endl;

    // 生成随机元素并加入散列表
    bool rec[_Matrix_Rows_][_Matrix_Columns_] = { false };  // 记录元素分布，以免重复
    int count = _Matrix_Rows_ * _Matrix_Columns_ * _Matrix_Sparseness_;

    cout << count << endl;

    for (int i = 0; i < count; ++i) {
        matElem<int> tmp = getRandom(_Matrix_Rows_, _Matrix_Columns_);
        // cout << i << '\t' << rec[tmp.row()][tmp.col()] << endl;
        if (rec[tmp.row()][tmp.col()]) {
            --i;
        } else {
            ht.insert(tmp);
            rec[tmp.row()][tmp.col()] = true;
        }
    }

    return 0;
}


/******************** function implementation *********************************/

// 计算哈希表的规模
int tableSize(const int mr, const int mc, const double ms, const double lf) {
    // 计算有效值个数并保证负载因子不超过lf
    int si = mr * mc * ms / lf;

    // 寻找不小于（保证lf）上述结果的最小素数
    si += !(si % 2);
    while (!isPrime(si)) {
        si += 2;
    }

    return si;
}


// 哈希函数
template <class elemType>
int matelem2key(const matElem<elemType>& elem) {
    int hash = elem.row() * 100 + elem.col();

    return hash;
}
