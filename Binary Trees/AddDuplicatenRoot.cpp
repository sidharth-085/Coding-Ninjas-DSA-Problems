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

void insertDuplicateNode(BinaryTreeNode<int> *root) { // Post Order
    if (root==NULL) {
        return;        
    }
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    BinaryTreeNode<int> *leftNode = root->left;
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    root->left = newNode;
    newNode->left = leftNode;
}

void insertDuplicateNode(BinaryTreeNode<int> *root) { // Pre order
    if (root==NULL) {
        return;        
    }
    BinaryTreeNode<int> *leftNode = root->left;
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    root->left = newNode;
    newNode->left = leftNode;
    insertDuplicateNode(newNode->left);
    insertDuplicateNode(root->right);
}