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

// Method 1

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
	if (root==NULL) {
		return -1;		
	}
	if (root->data == a or root->data ==b) {
		return root->data;
	}
	int leftLCA = getLCA(root->left, a, b);
	int rightLCA = getLCA(root->right, a, b);
	if (leftLCA == -1 && rightLCA == -1) {
		return -1;
	}
	else if(leftLCA == -1 && rightLCA != -1) {
		return rightLCA;
	}
	else if (leftLCA != -1 && rightLCA == -1)  {
		return leftLCA;
	}
	return root->data;
}

// Method 2

BinaryTreeNode<int>* helper(BinaryTreeNode<int> *root, int a, int b) {
    if (root==NULL) {
        return NULL;
    }
    if (root->data == a || root->data == b) {
        return root;
    }
    BinaryTreeNode<int> *leftLCA = helper(root->left, a, b);
    BinaryTreeNode<int> *rightLCA = helper(root->right, a, b);
    
    if (leftLCA == NULL && rightLCA == NULL) {
        return NULL;
    }
    else if (leftLCA && rightLCA) {
        return root;
    }
    else if (leftLCA) {
        return leftLCA;       
    }
    return rightLCA; 
    // if leftLCA & rightLCA both are null as well as if rightLCA is not null but 
    // leftLCA is null, this statement returns correctly. 
}

int getLCA(BinaryTreeNode<int> *root, int a, int b) {
    root = helper(root, a, b);
    if (root) {
        return root->data;
    }
    return -1;
}