#include <iostream>
using namespace std;

template <typename T> 
class TreeNode {
    public:
    T data;
    vector<TreeNode<int>*> children;
    TreeNode(T data) {
        this->data = data;
    }
};

TreeNode<int>* maxSumNode(TreeNode<int> *root) {
    if (root==NULL) {
        return root;
    }
    TreeNode<int> *maxSumTreeNode = root;
    int maxSum = root->data;
    for (int i=0; i<root->children.size(); i++) {
        maxSum = maxSum + root->children[i]->data;                 
    }

    for (int i=0; i<root->children.size(); i++) {
        TreeNode<int> *childNode = maxSumNode(root->children[i]);
        int childMaxSum = childNode->data;
        for (int j=0; j<childNode->children.size(); j++) {
            childMaxSum = childMaxSum + childNode->children[j]->data;
        }
        if (maxSum < childMaxSum) {
            maxSum = childMaxSum;
            maxSumTreeNode = childNode;
        }                             
    }
    return maxSumTreeNode;
}