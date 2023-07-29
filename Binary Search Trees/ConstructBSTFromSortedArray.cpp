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

// METHOD 1

BinaryTreeNode<int>* constructTreeHelper(int *arr, int si, int ei) {
    if (si > ei) {
        return NULL;
    }
    int mid = (si+ei)/2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    root->left = constructTreeHelper(arr, si, mid-1);
    root->right = constructTreeHelper(arr, mid+1, ei);
    return root;
}

BinaryTreeNode<int>* constructTree(int *arr, int size) {
    return constructTreeHelper(arr, 0, size-1);
}