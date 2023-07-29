#include <iostream>
#include <vector>
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

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	if (root==NULL) {
		return NULL;
	}
	vector<int> *vec = new vector<int>;
	if (root->data==data) {
		vec->push_back(root->data);
        return vec;		
	}
    vector<int> *leftVec = getPath(root->left, data);
    if (leftVec) {
        leftVec->push_back(root->data);
        return leftVec;
    }
    vector<int> *rightVec = getPath(root->right, data);
    if (rightVec) {
        rightVec->push_back(root->data);
        return rightVec;
    }
    return NULL;
}