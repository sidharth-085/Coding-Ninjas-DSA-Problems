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

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
    if (root == NULL) {
        return false;
    }

    if (root->data == x) {
        return true;
    }

    if (isNodePresent(root->left, x) || isNodePresent(root->right, x)) {
        return true;
    }
    return false;
    // return isNodePresent(root->left, x) || isNodePresent(root->right, x);
    // above statement can be replaced by single line.
}