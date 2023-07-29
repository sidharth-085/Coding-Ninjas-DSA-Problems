#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }
};

void rootToLeafPathsSumToK_Helper(BinaryTreeNode<int> *root, int sum, vector<int> path) {
    if (root == NULL) {
        return;
    }
    path.push_back(root->data);
    if (root->left == NULL && root->right == NULL) {
        if (sum == root->data) {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    rootToLeafPathsSumToK_Helper(root->left, sum - root->data, path);
    rootToLeafPathsSumToK_Helper(root->right, sum - root->data, path);
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int sum) {
    vector<int> path;
    rootToLeafPathsSumToK_Helper(root, sum, path);
}