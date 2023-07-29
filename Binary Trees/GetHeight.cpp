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

int height(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    int heightLeft = height(root->left);
    int heightRight = height(root->right);
    return max(heightLeft, heightRight) + 1;
}