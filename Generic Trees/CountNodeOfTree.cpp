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

int countNodesOfTree(TreeNode<int> *root) {
    if (root==NULL) {
        return 0;
    }
    int count = 0;
    for (int i=0; i<root->children.size(); i++) {
        int numOfChild = countNodesOfTree(root->children[i]);
        count = count + numOfChild;
    }
    return count+1;
}

int main() {

}