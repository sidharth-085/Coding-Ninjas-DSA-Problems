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

bool areIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
    if (root1==NULL && root2==NULL) {
        return true;
    }
    if (root1==NULL || root2==NULL) {
        return false;
    }   
    if (root1->data!=root2->data || root1->children.size()!=root2->children.size()) {
        return false;
    }
    for (int i=0; i<root1->children.size(); i++) {
        bool ans = areIdentical(root1->children[i], root2->children[i]);
        if (!ans) {
            return false;
        }    
    }
    return true;
}