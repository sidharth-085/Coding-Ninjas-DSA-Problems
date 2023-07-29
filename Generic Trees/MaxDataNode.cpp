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

TreeNode<int>* maxDataNode(TreeNode<int> *root) {
    TreeNode<int> *maxDataTreeNode = root;
    for (int i=0; i<root->children.size(); i++) {
        TreeNode<int> *maxChildNode = maxDataNode(root->children[i]);
        if (maxDataTreeNode->data < maxChildNode->data) {
            maxDataTreeNode = maxChildNode;
        }
    }
    return maxDataTreeNode;
}

int main() {

}