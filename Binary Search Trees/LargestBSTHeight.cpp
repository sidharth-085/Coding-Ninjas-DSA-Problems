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

class Helper {
    public:
    int min;
    int max;
    bool isBST;
    int largestSubtreeHeight;
};

Helper largestBSTSubtreeHelper(BinaryTreeNode<int>* root) {
    if (root == NULL) {
        Helper output;
        output.min = INT_MAX;
        output.max = INT_MIN;
        output.isBST = true;
        output.largestSubtreeHeight = 0;
        return output;
    }

    Helper leftAns = largestBSTSubtreeHelper(root->left);
    Helper rightAns = largestBSTSubtreeHelper(root->right);

    Helper ans;
    ans.min = min(root->data, min(leftAns.min, rightAns.min));
    ans.max = max(root->data, max(leftAns.max, rightAns.max));

    if (leftAns.isBST && rightAns.isBST && root->data > leftAns.max && root->data < rightAns.min) {
        ans.isBST = true;
        ans.largestSubtreeHeight = max(leftAns.largestSubtreeHeight, rightAns.largestSubtreeHeight) + 1;
    } else {
        ans.isBST = false;
        ans.largestSubtreeHeight = max(leftAns.largestSubtreeHeight, rightAns.largestSubtreeHeight);
    }
    return ans;
}

int largestBSTSubtree(BinaryTreeNode<int>* root) {
    Helper result = largestBSTSubtreeHelper(root);
    return result.largestSubtreeHeight;
}