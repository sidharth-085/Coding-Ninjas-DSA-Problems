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

int getHeight(TreeNode<int>* root) {
    int maxChildHeight = 0;
    for (int i=0; i<root->children.size(); i++) {
        int childHeight = getHeight(root->children[i]);
        if (maxChildHeight < childHeight) {
            maxChildHeight = childHeight;
        }
    }
    return maxChildHeight+1;
}