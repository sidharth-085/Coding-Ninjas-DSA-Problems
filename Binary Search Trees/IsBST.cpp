#include <iostream>
#include <climits>
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

// METHOD 1

bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->data > max || root->data < min) {
        return false;
    }

    bool leftHalf = isBST(root->left, min, root->data);
    bool rightHalf = isBST(root->right, root->data, max);

    if (leftHalf == true && rightHalf == true) {
        return true;
    }
    return false;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// METHOD 2

pair<int,int> getMinAndMax(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return {INT_MAX, INT_MIN};
    }
    pair<int,int> leftPair = getMinAndMax(root->left);
    pair<int,int> rightPair = getMinAndMax(root->right);

    int minData = min(root->data, min(leftPair.first, rightPair.first));
    int maxData = max(root->data, max(leftPair.second, rightPair.second));

    return {minData, maxData};
}

bool isBST(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return true;
    }
    int getLeftMax = getMinAndMax(root->left).second;
    int getRightMin = getMinAndMax(root->right).first;
    bool output = (root->data > getLeftMax) && (root->data < getRightMin)
                   && (isBST(root->left) && isBST(root->right));
    return output;
}

// METHOD 3

pair<pair<int,int>, bool> helper(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        pair <int,int> temp = make_pair(INT_MAX, INT_MIN);
        return make_pair(temp, true);
        // return make_pair(make_pair(INT_MAX, INT_MIN), true);
    }
    pair<pair<int,int>, bool> leftAns = helper(root->left);
    pair<pair<int,int>, bool> rightAns = helper(root->right);
    // for leftAns & rightAns, first is pair class and first of pair is Min & second is Max.
    // for leftAns & rightAns, second is boolean check of tree is BST or not.
    bool isBST = ((root->data > leftAns.first.second) && (root->data <= rightAns.first.first)
                  && leftAns.second && rightAns.second);
    int finalMin = min(root->data, min(leftAns.first.first, rightAns.first.first));
    int finalMax = max(root->data, max(leftAns.first.second, rightAns.first.second));
    return make_pair(make_pair(finalMin, finalMax), isBST);
}

bool isBST(BinaryTreeNode<int> *root) {
    pair<pair<int,int>, bool> output = helper(root);
    return output.second;
}