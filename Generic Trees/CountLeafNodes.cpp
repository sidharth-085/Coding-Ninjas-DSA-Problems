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

int getLeafNodeCount(TreeNode<int>* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->children.size() == 0) {
        return 1;
    }
    int leafCount = 0;
    for (int i = 0; i < root->children.size(); i++) {
        int childLeafCount = getLeafNodeCount(root->children[i]);
        leafCount = leafCount + childLeafCount;
    }
    return leafCount;
}