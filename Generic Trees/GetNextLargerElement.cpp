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

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    if (root==NULL) {
        return root;
    }
    if (root->data > x) {
        return root;
    }
    for (int i=0; i<root->children.size(); i++) {
        TreeNode<int> *currNode = root->children[i];
        if (currNode->data > x) {
            return currNode;
        }
        TreeNode<int> *ansNode = getNextLargerElement(currNode, x);
        if (ansNode!=NULL) {
            return ansNode;
        }
    }
    return NULL;
}