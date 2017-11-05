# Binary Tree 判断是否为完全二叉树

> 姓名：申佳旻
>
> 学号：516021910528
>
> 邮箱：john980118@sjtu.edu.cn

## `isComplete`

### 问题分析

由性质4

> 教材第109页
>
> 性质4	具有$n$个节点的完全二叉树的高度$k=[log_2 n] + 1$	
>
> P.S. 我不会用latex写向下取整，断网了又没法查orz

利用原有函数`int size()`和`int height()`，得到二叉树的节点数$n$与高度$k$，然后判断是否满足上述等式即可。

### 代码实现

> `BinaryTree.h` Line 173-184

```cpp
template <class Type>
bool BinaryTree<Type>::isComplete() {
    int k = height();	// 获取二叉树的高度k
    int n = size();		// 获取二叉树的节点数n
    int ck = 1;			// 初始化calculated_k为1

    while (n >= 2) {	// 将$[log_2 n]$的值加到calculated_k上
        ck++;
        n /= 2;
    }
    return k == ck;		//  判断等式是否成立
}
```



## `BinaryTree.h`的编译问题

> 前题已述