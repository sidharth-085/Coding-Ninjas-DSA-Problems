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

// 2 types of traversals: Pre-order and Post-order

// E.g; Input Tree: 10 3 20 30 40 2 400 50 0 0 0 0 

// Pre-Order Output: 10 20 400 50 30 40 

// Post-Order Output: 400 50 20 30 40 10

void preOrderTraversal(TreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    cout << root->data << " ";
    for (int i=0; i<root->children.size(); i++) {
        preOrderTraversal(root->children[i]);
    }
}

void postOrderTraversal(TreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    for (int i=0; i<root->children.size(); i++) {
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

int main() {

}