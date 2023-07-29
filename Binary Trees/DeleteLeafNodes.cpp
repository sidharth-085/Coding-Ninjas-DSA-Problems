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

BinaryTreeNode<int>* deleteLeafNodes(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return NULL;
    }
    if (root->left==NULL && root->right==NULL) {
        delete root;
        return NULL;
    }
    root->left = deleteLeafNodes(root->left);
    root->right = deleteLeafNodes(root->right);
    return root;
}