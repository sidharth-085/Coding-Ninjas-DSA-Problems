#include <iostream>
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

// Method 1

int heightOfTree(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int diameterOfTree(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return 0;
    }
    int option1 = heightOfTree(root->left) + heightOfTree(root->right);
    int option2 = diameterOfTree(root->left);
    int option3 = diameterOfTree(root->right);
    return max(option1, max(option2, option3));
}

// Method 2

// first contains height and second contains diameter.

pair<int, int> heightDiameter(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return make_pair(0,0); // it creates a pair class of 0 in first & 0 in second and return.
    }
    pair<int,int> left = heightDiameter(root->left);
    pair<int,int> right = heightDiameter(root->right);

    int height = max(left.first, right.first) + 1;
    int diameter = max(left.first+right.first, max(left.second, right.second));

    return make_pair(height, diameter);
}

// in main just print or call second for pair class.
