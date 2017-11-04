template <class elemType>
class linkQueue: public queue<elemType> {
private:
    struct node {
        elemType data;
        node *next;
        node(const elemType& x, node *N = NULL) {
            data = x;
            next = N;
        }

        node(): next(NULL) {}
        ~node() {}
    };
    node *front, *rear;
public:
    linkQueue() {
        front = rear = NULL;
    }

    ~linkQueue();
    bool isEmpty() {
        return front == NULL;
        //注意队空条件
    }

    void enQueue(const elemType& x);
    elemType deQueue();

    elemType getHead() {
        return front->data;
    }
};


template <class elemType>
linkQueue<elemType>::~linkQueue() {
    node *tmp;

    while (front != NULL) {
        //从front开始顺序释放空间
        tmp = front;
        front = front->next;
        delete tmp;
    }
}


template <class elemType>
void linkQueue<elemType>::enQueue(const elemType& x) {
    //入队发生在链表尾部
    if (rear == NULL) {
        //如果队列为空
        front = rear = new node(x);
    } else {
        rear->next = new node(x);
        rear = rear->next;
    }
}


template <class elemType>
elemType linkQueue<elemType>::deQueue() {
    node *p = front;
    //最好先判断队列是否为空
    elemType value = front->data;

    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }

    //front==NULL说明队已空
    delete p;
    return value;
}
