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

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int min, int max) {
    if (root==NULL) {
        return;
    }
    // Range: 20 to 30 & 50 to 60
    //         40
    //    20       60
    // 10   30   50   70
    if (root->data >= min && root->data <= max) {
        elementsInRangeK1K2(root->left, min, max);
        cout << root->data << " ";
        elementsInRangeK1K2(root->right, min, max);
    }
    else if (root->data > max) {
        elementsInRangeK1K2(root->left, min, max);
    }
    else if (root->data < min) {
        elementsInRangeK1K2(root->right, min, max);
    }     
}