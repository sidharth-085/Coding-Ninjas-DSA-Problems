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

void helper(TreeNode<int> *root, int depth) {
    root->data = depth;
    for (int i=0; i<root->children.size(); i++) {
        helper(root->children[i], depth+1);
    }
}

void replaceWithDepthValue(TreeNode<int>* root) {
    if (root==NULL) {
        return;
    }
    int depth = 0;
    helper(root, depth);
}