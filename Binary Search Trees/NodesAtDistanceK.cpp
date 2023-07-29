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

void nodeAtDepthKdown(BinaryTreeNode<int> *root, int k) {
    // this function prints the node's data at depth k down the rooted tree.
    if (root==NULL) {
        return;
    }
    if (k==0) {
        cout << root->data << endl;
        return;
    }
    nodeAtDepthKdown(root->left, k-1);
    nodeAtDepthKdown(root->right, k-1);
}

// this function returns DISTANCE FROM ROOT TO TARGET NODE.
int nodesAtDistanceKhelper(BinaryTreeNode<int> *root, int target, int k) {
    if (root==NULL || k < 0) { // it checks if root is null or last element comes so returns -1;
        return -1;
    }
    if (root->data == target) {
        // if the root's data is equal to target, print all data below depth k.
        nodeAtDepthKdown(root, k);
        return 0;
    }

    int leftDistance = nodesAtDistanceKhelper(root->left, target, k);
    // Then, if target node is not present at root. Then, we have to search in left subtree.
    // 
    if (leftDistance != -1) {
        if (leftDistance + 1 == k) {
            cout << root->data << endl;
        }
        else {
            int rootToRightDistance = k - leftDistance - 2; // k - (leftDistance + 1) - 1
            nodeAtDepthKdown(root->right, rootToRightDistance);
        }
        return leftDistance + 1;
    }

    int rightDistance = nodesAtDistanceKhelper(root->right, target, k);
    if (rightDistance != -1) {
        if (rightDistance + 1 == k) {
            cout << root->data << endl;
        }
        else {
            int rootToLeftDistance = k - rightDistance - 2; // k - (rightDistance + 1) - 1
            nodeAtDepthKdown(root->left, rootToLeftDistance);
        }
        return rightDistance + 1;
    }
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int target, int k) {
    int ans = nodesAtDistanceKhelper(root, target, k);
}