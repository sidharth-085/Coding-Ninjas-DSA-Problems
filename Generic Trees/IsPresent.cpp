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

bool isPresent(TreeNode<int> *root, int x) {
    if (root==NULL) {
        return false;
    }
    if (root->data==x) {
        return true;
    }
    bool ans = false;
    for (int i=0; i<root->children.size(); i++) {
        ans = isPresent(root->children[i], x);
        if (ans) {
            return true;
        }
    }
    return false;
}