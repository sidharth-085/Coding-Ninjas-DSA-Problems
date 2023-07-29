#include <iostream>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

int countNodes(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return 0;
    }
    int count = countNodes(root->left) + countNodes(root->left);
    return count+1;
}