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

// Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two 
// nodes are cousins of each other or not. Two nodes are said to be cousins of each 
// other if they are at same level of the Binary Tree and have different parents.

// METHOD 1

class NodeInfo {
    public:
    BinaryTreeNode<int> *parent;
    int depth;

    NodeInfo() {
        parent = NULL;
        depth = 0;
    }
};

NodeInfo* findNodeInfo(BinaryTreeNode<int> *root, int node) {
    if (root==NULL) {
        return NULL;
    }
    if (root->data == node) {
        NodeInfo *output = new NodeInfo();
        output->parent = NULL;
        output->depth = 0;
        return output;
    }
    NodeInfo *leftAns = findNodeInfo(root->left, node);
    if (leftAns != NULL) {
        leftAns->depth = leftAns->depth + 1;
        leftAns->parent = root;
        return leftAns;
    }

    NodeInfo *rightAns = findNodeInfo(root->right, node);
    if (rightAns != NULL) {
        rightAns->depth = rightAns->depth + 1;
        rightAns->parent = root;
        return leftAns;
    }

    return NULL;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if (root==NULL) {
        return -1;
    }
    NodeInfo *pInfo = findNodeInfo(root, p);
    NodeInfo *qInfo = findNodeInfo(root, q);

    if (pInfo->depth == qInfo->depth && pInfo->parent != qInfo->parent) {
        return true;
    }
    return false;
}

// METHOD 2

int depth(BinaryTreeNode<int> *root, int k) {
    if (root==NULL) {
        return -1;
    }
    if (root->data == k) {
        return 0;
    }
    int left = depth(root->left, k);
    if (left != -1) {
        return left + 1;
    }

    int right = depth(root->right, k);
    if (right != -1) {
        return right + 1;
    }
    return -1;
}

bool isSibling(BinaryTreeNode<int> *root, int p, int q) {
    if (root==NULL) {
        return false;
    }
    if (root->left && root->right) {
        if (root->left->data == p && root->right->data == q) {
            return true;
        }
        else if (root->left->data == q && root->right->data == p) {
            return true;
        }
        else {
            bool leftAns = isSibling(root->left, p, q);
            bool rightAns = isSibling(root->right, p, q);
            return leftAns || rightAns;
        }
    }
    if (root->left) {
        return isSibling(root->left, p, q);
    }
    if (root->right) {
        return isSibling(root->right, p, q);
    }
    return false;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    return (depth(root, p) == depth(root, q)) && (isSibling(root, p, q) == false); 
}