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

BinaryTreeNode<int>* binarySearch(BinaryTreeNode<int> *root, int x) {
    if (root==NULL) {
        return NULL;
    }
    if (root->data < x) {
        return binarySearch(root->right, x);
    }
    else if (root->data > x) {
        return binarySearch(root->left, x);
    }
    else {
        return root;
    }
    return NULL;
}

bool searchInBST(BinaryTreeNode<int> *root , int k) { // check is K present in Tree or not.
	if (root==NULL) {
        return false;
    }
	bool ans = false;
	if (root->data == k) {
		return true;
	}
	else if (root->data < k) {
		ans = searchInBST(root->right, k);
	}
	else {
		ans = searchInBST(root->left, k);
	}
	return ans;
}