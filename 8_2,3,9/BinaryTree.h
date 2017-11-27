#include <vector>

using namespace std;

template <class elemType>
class BinaryTree {
private:
    vector<Node> store_;
    size_t nodeNum() const; // 假定为完全二叉树，树中节点的个数
    void s_assign(size_t index, const elemType& data); // 单个赋值
    bool s_remove(size_t index); // 单个删除

public:
    class Node;
    BinaryTree(): store_(1) {
        // 构造空二叉树
    }
    BinaryTree(const elemType& rootdata): store_(2) {
        // 从根节点数据建立一个树
        store_[1] = Node(this, rootdata);
    }
    BinaryTree(const& root) {
        // 从一个节点建立一个树。要把整个子树都搞过来
        // store_[1] = root.data
    }
    BinaryTree(const BinaryTree& another): store_(another.store_) {
        // 拷贝构造函数
    }
    ~BinaryTree() {
        // 析构二叉树
        clear();
    }
    void create();

    void clear() {
        for (size_t i = 0; i < store_.size(); i++) {
            store_[i].clear();
        }
        store_.resize(1, NULL);
    }
    bool isEmpty() const {
        return (bool) nodeNum();
    }
    void MakeTree(elemType rootelem, BinaryTree& Tl, BinaryTree& Tr) {
        // 嘛。。又要把两棵树并一起
    }
    void preOrderTraverse(void (*f)(const & elemType));
    void midOrderTraverse(void (*f)(const & elemType));
    void postOrderTraverse(void (*f)(const & elemType));
    void HierarchicalTraverse(void (*f)(const & elemType));

    elemType *root() const {
        if (nodeNum()) {
            return store_[1];
        } else {
            return NULL;
        }
    }
    elemType *parent(const elemType *head) const;
    elemType *lchild(const elemType *head) const;
    elemType *rchild(const elemType *head) const;

    bool delLeft(const elemType& head);
    bool delRight(const elemType& head);
};


template <class elemType>
class Node {
private:
    size_t index_;
    BinaryTree<elemType> *bt_;
    elemType data_;
public:
    Node(): index_(0) {}
    Node(const BinaryTree<elemType> *bt, const elemType& data): bt_(bt), data_(data) {
        index_ = this - &bt_->store_[0];
    }
    ~Node();
    bool empty() {
        return index_ ? false : true;
    }
    void clear() {
        index_ = 0;
        bt_ = NULL;
    }
    elemType& data() {
        return data_;
    }
    Node& parent() {
        if (index_ == 1) {
            return *this;
        } else {
            return bt_->store_[iondex_ / 2];
        }
    }
    Node& left() {
        if (2 * index_ > bt.nodeNum()) {
            return bt_->store_[0];
        } else {
            return bt_->store_[2 * index_];
        }
    }
    Node& right() {
        if (2 * index_ + 1 > bt.nodeNum()) {
            return bt_->store_[0];
        } else {
            return bt_->store_[2 * index_ + 1];
        }
    }
};


template <class elemType>
size_t BinaryTree<elemType>::nodeNum() const {
    // 假定为完全二叉树，树中节点的个数
    return store_.size() - 1;
}


template <class elemType>
void BinaryTree<elemType>::s_assign(size_t index, const elemType& data) {
    // 单个赋值
    if (index >= store_.size()) {
        // 若index超过size的范围，则需resize
        size_t newsize = index + 1;

        if (newsize > store_.capacity()) {
            // 若resize会触发重新分配，则使capacity倍增，减少重新分配的次数
            size_t newcapacity = newsize * 2;
            while (newsize > newcapacity) {
                newcapacity *= 2;
            }
            store_.reserve(newcapacity);
        }
        // 调用resize增大长度并使用空指针初始化
        store_.resize(newsize);
    }
    // 设定新值
    store_[index] = Node(this, data);
}


template <class elemType>
bool BinaryTree<elemType>::s_remove(size_t index) {
    // 单个删除
    if ((index < store_.size()) && store_[index]) {
        // index处原非空，析构，清空指针
        store_[index].clear();

        if (index == store_.size() - 1) {
            // index为树的最后一个节点，删除后树的节点数减小
            while (!store_[index]) {
                // 跳过结尾的空元素
                index--;
            }
            store_.resize(index + 1);
        }
        return true;
    } else {
        // index处原为空
        return false;
    }
}
