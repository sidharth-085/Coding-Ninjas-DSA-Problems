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

void replaceWithLargerNodesSumHelper(BinaryTreeNode<int>* root, int& sum) {
    if (root == NULL) {
        return;
    }
    replaceWithLargerNodesSumHelper(root->right, sum);
    root->data = root->data + sum;
    sum = root->data;
    replaceWithLargerNodesSumHelper(root->left, sum);
}

void replaceWithLargerNodesSum(BinaryTreeNode<int>* root) {
    int sum = 0;
    replaceWithLargerNodesSumHelper(root, sum);
}