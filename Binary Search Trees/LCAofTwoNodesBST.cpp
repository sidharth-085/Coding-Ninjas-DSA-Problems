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

BinaryTreeNode<int>* getLCAHelper(BinaryTreeNode<int> *root, int a, int b) {
    if (root==NULL) {
        return NULL;
    }
    if (root->data == a or root->data == b) {
        return root;
    }
    BinaryTreeNode<int> *leftLCA = getLCAHelper(root->left, a, b);
    BinaryTreeNode<int> *rightLCA = getLCAHelper(root->right, a, b);
    if (root->data > a && root->data > b) {
        return leftLCA;
    }
    if (root->data < a && root->data < b) {
        return rightLCA;
    }

    if (leftLCA && rightLCA) {
        return root;
    }
    else if (leftLCA) {
        return leftLCA;
    }
    return rightLCA;
}

int getLCA(BinaryTreeNode<int> *root, int a, int b) {
    root = getLCAHelper(root, a, b);
    if (root) {
        return root->data;
    }
    return -1;
}

// METHOD 2

int getLCA(BinaryTreeNode<int>* root , int a, int b) {
	if (root==NULL) {
		return -1;		
	}
	if (root->data == a or root->data ==b) {
		return root->data;
	}
	int leftLCA = getLCA(root->left, a, b);
	int rightLCA = getLCA(root->right, a, b);

    if (root->data > a && root->data > b) {
        return leftLCA;
    }
    if (root->data < a && root->data < b) {
        return rightLCA;
    }

    if (leftLCA != -1 && rightLCA != -1) {
        return root->data;
    }
    else if (leftLCA != -1) {
        return leftLCA;
    }
    return rightLCA;
}