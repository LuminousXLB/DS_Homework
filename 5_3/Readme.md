# Binary Tree 层级遍历

> 姓名：申佳旻
>
> 学号：516021910528
>
> 邮箱：john980118@sjtu.edu.cn





## `BinaryTree.h`

在编译时，`BinaryTree.h` 中下面一段代码会报出`[-Wreorder]`警告。

```c++
template <class Type>
class BinaryTree<Type>::Node {
public:
    Node *left, *right;
    Type data;
    Node(): left(NULL), right(NULL) {}
    Node(Type item, Node * L = NULL, Node * R = NULL): data(item), left(L), right(R) {}
    ~Node() {}
};
```

```
In file included from main.cpp:2:0:
BinaryTree.h: In instantiation of 'BinaryTree<Type>::Node::Node(Type, BinaryTree<Type>::Node*, BinaryTree<Type>::Node*) [with Type = int]':
BinaryTree.h:17:16:   required from 'BinaryTree<Type>::BinaryTree(const Type&) [with Type = int]'
main.cpp:8:25:   required from here
BinaryTree.h:142:10: warning: 'BinaryTree<int>::Node::data' will be initialized after [-Wreorder]
     Type data;
          ^~~~
BinaryTree.h:141:11: warning:   'BinaryTree<int>::Node* BinaryTree<int>::Node::left' [-Wreorder]
     Node *left, *right;
           ^~~~
BinaryTree.h:144:5: warning:   when initialized here [-Wreorder]
     Node(Type item, Node * L = NULL, Node * R = NULL): data(item), left(L), right(R) {}
     ^~~~
```

经查阅资料

> [警告： 在此处初始化后被初始化 [-Wreorder]](http://blog.csdn.net/qustdjx/article/details/8058122)
>
> 如果代码中的成员变量的初始化顺序和它们实际执行时初始化顺序不一致，给出警告。

尝试改为

```c++
    Node *left = NULL, *right = NULL;
```

确能消除一条warning，但是

- 两个构造函数都对`left`与`right`进行了明确的初始化，符合一个正常的类的定义的写法，无法理解“初始化顺序不一致”的意思
- 推测另两条warning可通过对`Type data`进行初始化消除，但`data`的类型不能确定，无法进行初始化。

> 编译器版本
>
> ```
> Using built-in specs.
> COLLECT_GCC=g++
> COLLECT_LTO_WRAPPER=c:/mingw/bin/../libexec/gcc/mingw32/6.3.0/lto-wrapper.exe
> Target: mingw32
> Configured with: ../src/gcc-6.3.0/configure --build=x86_64-pc-linux-gnu --host=mingw32 --with-gmp=/mingw --with-mpfr=/mingw --with-mpc=/mingw --with-isl=/mingw --prefix=/mingw --disable-win32-registry --target=mingw32 --with-arch=i586 --enable-languages=c,c++,objc,obj-c++,fortran,ada --with-pkgversion='MinGW.org GCC-6.3.0-1' --enable-static --enable-shared --enable-threads --with-dwarf2 --disable-sjlj-exceptions --enable-version-specific-runtime-libs --with-libiconv-prefix=/mingw --with-libintl-prefix=/mingw --enable-libstdcxx-debug --with-tune=generic --enable-libgomp --disable-libvtv --enable-nls
> Thread model: win32
> gcc version 6.3.0 (MinGW.org GCC-6.3.0-1)
> ```
>
> 编译命令
>
> ```bash
> g++ -Wall
> ```

