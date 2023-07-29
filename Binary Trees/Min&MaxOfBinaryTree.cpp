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

// Method 1

pair<int,int> getMinAndMax(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return make_pair(INT_MAX, INT_MIN);
    }
    pair<int,int> leftPair = getMinAndMax(root->left);
    pair<int,int> rightPair = getMinAndMax(root->right);

    int minData = min(root->data, min(leftPair.first, rightPair.first));
    int maxData = max(root->data, max(leftPair.second, rightPair.second));

    return make_pair(minData, maxData);
}

// Method 2

pair<int,int> getMinAndMax(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return make_pair(INT_MAX, INT_MIN);
    }
    pair<int,int> ans = make_pair(INT_MAX, INT_MIN);
    if (root->left) {
        pair<int, int> leftPair = getMinAndMax(root->left);
        ans.first = min(ans.first, leftPair.first);
        ans.second = max(ans.second, leftPair.second);
    }
    if (root->right) {
        pair<int, int> rightPair = getMinAndMax(root->right);
        ans.first = max(ans.first, rightPair.first);
        ans.second = max(ans.second, rightPair.second);
    }

    ans.first = min(root->data, ans.first);
    ans.second = max(root->data, ans.second);
    return ans;
}