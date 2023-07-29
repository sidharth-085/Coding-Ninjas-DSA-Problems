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

int getLargeNodeCount(TreeNode<int>* root, int x) {
    if (root==NULL) {
        return 0;
    }
    int count = 0;
    if (root->data > x) {
        count++;              
    }
    for (int i=0; i<root->children.size(); i++) {
        count = count + getLargeNodeCount(root->children[i], x);
    }
    return count;
}