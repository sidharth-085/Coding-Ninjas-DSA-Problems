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

// General Approach.

int height(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
}

bool isBalanced(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return true;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    bool isLeftBalanced = isBalanced(root->left);
    bool isRightBalanced = isBalanced(root->right);

    int heightDiff = abs(leftHeight-rightHeight);
    bool ans = isLeftBalanced && isRightBalanced && (heightDiff<=1);
    return ans;
}

// Much Better Code with pair class.

pair<int, bool> isBalancedHelper(BinaryTreeNode<int> *root) {
    if (root == NULL) {
        // Base case: An empty tree is balanced with height 0
        return make_pair(0, true);
    }

    // Recursively check the left and right subtrees
    pair<int, bool> left = isBalancedHelper(root->left);
    pair<int, bool> right = isBalancedHelper(root->right);

    // Calculate the height of the current node
    int currentHeight = max(left.first, right.first) + 1;

    // Check if both subtrees are balanced and the height difference is at most 1
    bool isCurrentBalanced = left.second && right.second && abs(left.first - right.first) <= 1;

    // Return the height and balanced status for the current subtree
    return make_pair(currentHeight, isCurrentBalanced);
}

bool isBalanced(BinaryTreeNode<int> *root) {
    pair<int, bool> result = isBalancedHelper(root);
    return result.second;
}
