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

vector<int>* longestPath(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        return NULL;
    }   
    vector<int>* vecMax = new vector<int>();
       
    if (root->left == NULL && root->right == NULL) {
        vecMax->push_back(root->data);
        return vecMax;
    }
    
    vector<int>* leftAns = longestPath(root->left);
    if (leftAns != NULL) {
        leftAns->push_back(root->data);
        if (leftAns->size() > vecMax->size()) {
            vecMax = leftAns;
        }
    }
    
    vector<int>* rightAns = longestPath(root->right);
    if (rightAns != NULL) {
        rightAns->push_back(root->data);
        if (rightAns->size() > vecMax->size()) {
            vecMax = rightAns;
        }
    }    
    return vecMax;
}