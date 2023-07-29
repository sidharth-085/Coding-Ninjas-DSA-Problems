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

int sumOfNodes(TreeNode<int> *root) {
    if (root==NULL) {
        return -1;
    }
    int sum = root->data;
    for (int i=0; i<root->children.size(); i++) {
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}

int main() {

}