#include <iostream>
#include <queue>
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

void printBinaryTree(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    cout << root->data << " : ";
    if (root->left) {
        cout << "L " << root->left->data << " ";
    }
    if (root->right) {
        cout << "R " << root->right->data << " ";
    }
    cout << endl;
    printBinaryTree(root->left);
    printBinaryTree(root->right);
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData==-1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();
    root->left = leftChild;
    root->right = rightChild;
    return root;
}

BinaryTreeNode<int> *takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    if (rootData==-1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> input;
    input.push(root);
    while (!input.empty()) {
        BinaryTreeNode<int>* front = input.front();
        input.pop();

        int leftChildData;
        cout << "Enter data for left child of " << front->data << " : ";
        cin >> leftChildData;
        if (leftChildData != -1) {
            BinaryTreeNode<int>* leftChild = new BinaryTreeNode<int>(leftChildData);
            input.push(leftChild);
            root->left = leftChild;
        }

        int rightChildData;
        cout << "Enter data for right child of " << front->data << " : ";
        cin >> rightChildData;
        if (rightChildData != -1) {
            BinaryTreeNode<int>* rightChild = new BinaryTreeNode<int>(rightChildData);
            input.push(rightChild);
            root->right = rightChild;
        }
    }
}