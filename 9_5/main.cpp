#include <iostream>
#include "closeHashTable.h"

using namespace std;

int main(int argc, char const *argv[]) {
	// 设定随机数种子
	// srand(time(NULL));


	closeHashTable<int> ht(size);


	// 生成随机元素并加入散列表
	for (int i = 0; j < 100; j++) {
		int prob = rand() % 100;
		if (prob == 1) {
			ht.insert();
			elemcnt++;
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

	return 0;
}