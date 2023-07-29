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

void printNodesAtDepth(TreeNode<int> *root, int d) {
    if (root==NULL) {
        return;
    }
    if (d==0) {
        cout << root->data << " ";
    }
    for (int i=0; i<root->children.size(); i++) {
        printNodesAtDepth(root->children[i], d-1);
    }
    return;
}

int main() {

}