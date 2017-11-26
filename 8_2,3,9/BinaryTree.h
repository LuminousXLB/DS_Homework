#include <vector>

using namespace std;

template <class elemType>
class BinaryTree {
private:
    vector<elemType *> store_;
    size_t nodeNum() const {
        // 假定为完全二叉树，树中节点的个数
        return store_.size() - 1;
    }
    void s_assign(size_t index, const elemType& data) {
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
            store_.resize(newsize, NULL);
        }
        if (store_[index]) {
            // index处原非空，先析构原有内容
            delete store_[index];
        } else {
            // index处原为空，则计数器递增
            ++nodeNum_;
        }
        // 设定新值
        store_[index] = new elemType(data);
    }
    bool s_remove(size_t index) {
        // 单个删除
        if ((index < store_.size()) && store_[index]) {
            // index处原非空，析构，清空指针
            delete store_[index];
            store_[index] = NULL;

            if (index == store_.size() - 1) {
                // index为树的最后一个节点，删除后树的节点数减小
                while (!store_[index]) {
                    // 跳过结尾的空元素
                    index--;
                }
                store_.resize(index + 1, NULL);
            }
            return true;
        } else {
            // index处原为空
            return false;
        }
    }
public:
    BinaryTree(): store_(1, NULL) {
        // 构造空二叉树
    }
    BinaryTree(const elemType& rootdata): store_(2, NULL) {
        // 从根节点数据建立一个树
        store_[1] = new elemType(rootdata);
    }
    // BinaryTree(const & root) {
    //     // 从一个节点建立一个树。要把整个子树都搞过来
    //     // store_[1] = root.data
    // }
    BinaryTree(const BinaryTree& another) {
        // 拷贝构造函数
        store_ = another.store_;
    }
    ~BinaryTree() {
        // 析构二叉树
        clear();
    }
    void create();
    void clear();
    bool isEmpty() const;
    void MakeTree(elemType rootelem, BinaryTree& Tl, BinaryTree& Tr);
    void traverse();

    iterator& root() const;
    iterator& parent(const iterator& head) const;
    iterator& lchild(const iterator& head) const;
    iterator& rchild(const iterator& head) const;

    bool delLeft(const iterator& head);
    bool delRight(const iterator& head);
};
