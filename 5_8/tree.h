#include "BinaryTree.h"

template <class elemType>
class tree: protected BinaryTree<elemType> {
private:
public:
    void preOrder() const {}
    void postOrder() const {}
    void midOrder() const {}
    void HierarchicalTraversal() const {}
}
