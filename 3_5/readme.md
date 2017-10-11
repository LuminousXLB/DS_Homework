# Pascal linter

> 配对
>
> - begin ... end ...
> - if ... then ... ( else ... )

## 关键字定义

```C++
enum key {BEGIN, IF, THEN, ELSE, END};
```

将可能出现的五个关键字设定位一个枚举类型。

  ## 实现

```C++
bool check (string filename);
```

参数：Pascal源代码的文件名

### 读取文件

```c++
ifstream reader(filename.c_str());
if(!reader) {
    throw FILE_OPEN_FAILED();
}
string word;
```

定义一个输入流对象，打开文件

如果打开失败抛出错误`FILE_OPEN_FAILED`

定义word准备逐次读取文件

### 栈定义

```c++
stack<key> pool;
```

定义一个栈准备接收读入的关键字

### 配对检查

#### 入栈

```c++
while (reader >> word) {
    if (word == "begin") {
        pool.push(BEGIN);
    } else if (word == "if") {
        pool.push(IF);
    } else if (word == "then") {
        pool.push(THEN);
    } else if (word == "else") {
        pool.push(ELSE);
    } else if (word == "end;" || word == "end.") {
    	//...
    }
}


```
从文件中逐词读入。如果为`begin`、`if`、`then`或`else`则直接入栈，读入`end`时开始出栈进行判断

#### 出栈

```c++
while (!pool.empty() && pool.top() != BEGIN) {
    key cur = pool.top();
    if (cur == ELSE) {
        pool.pop();
        if (pool.top() == THEN) {
            continue;
        } else {
            return false;
        }
    } else if (pool.top() == THEN) {
        pool.pop();
        if (pool.top() == IF) {
            pool.pop();
        } else {
            return false;
        }
    } else {
        return false;
    }
}

if (pool.empty()) {
    return false;
} else {
    pool.pop();
}
```

在一个`begin ... end`复合语句中，可能存在的情况有

- 不存在条件判断语句

  栈顶为`BEGIN`。与`END`配对，跳过循环直接出栈

- 存在条件判断语句，进入循环处理，直至成功与`END`配对

  - `if ... then ... `

    栈顶为`THEN`。若出栈后，栈顶为`IF`则配对成功，`IF`出栈

  - `if ... then ... else ... `

    栈顶为`ELSE`。若出栈后，栈顶为`THEN`则可能配对成功，重新进入循环，判断`THEN`是否正确匹配

  - 注：代码中可能出现`then`与`else`中间出现`begin ... end`的情况。但是读入`end`时，`begin`已被匹配掉，不影响下一步对`else`的匹配

### 返回结果

```c++
return pool.empty();
```

如果全部判断结束后，栈中恰好为空，则配对成功，否则配对失败。