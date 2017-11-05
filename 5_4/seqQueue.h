#include "queue.h"

template <class elemType>
class seqQueue: public queue<elemType> {
private:
    elemType *elem;
    int maxSize;  //队列容量
    int front, rear;  //队头队尾地址标记
    void doubleSpace();  //与第二章中的doubleSpace不同

public:
    seqQueue(int size = 10) {   //构造函数初始化队列
        elem = new elemType[size];
        maxSize = size;
        front = rear = 0;
    }
    //循环队列初始状态front=rear=0
    ~seqQueue() {
        delete elem;
    }
    bool isEmpty() {
        return front == rear;
    }
    void enQueue(const elemType& x);
    elemType deQueue();

    elemType getHead() {
        return elem[(front + 1) % maxSize];
    }
};     //front指向队头前一个单元
template <class elemType>
void seqQueue<elemType>::doubleSpace() {   //要保持队列结构
    elemType *tmp = elem;

    elem = new elemType[2 * maxSize];    //申请新数组
    for (int i = 1; i < maxSize; ++i) {  //i从1开始是因为新的front=0
        elem[i] = tmp[(front + i) % maxSize];   //拷贝方式跟原来不同
    }
    //把原来的队头[(front + 1) % maxSize]放到elem[1]
    front = 0;
    rear = maxSize - 1;               //重置队头队尾标志
    maxSize *= 2;    //maxSize跟着加倍，建立新的卷绕规则
    delete tmp;
}


template <class elemType>
void seqQueue<elemType>::enQueue(const elemType& x) {
    if ((rear + 1) % maxSize == front) {  //循环数组已满
        doubleSpace();
    }
    rear = (rear + 1) % maxSize;    //此时maxSize已变成原来2倍
    //rear往后挪一位
    elem[rear] = x;                         //并插入数据
}


template <class elemType>
elemType seqQueue<elemType>::deQueue() {
    //此处或许该先判断一下队列是否已经为空
    front = (front + 1) % maxSize;    //front往后挪一个，即队头后移
    return elem[front];    //返回原来队头的值
}
