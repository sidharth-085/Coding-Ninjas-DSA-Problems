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

class BST {
    BinaryTreeNode<int> *root;

    public:

    BST() {
        root = NULL;
    }

    private:

    bool isDataPresent(BinaryTreeNode<int> *node, int data) { 
        // helper because we have dont have node as argument in search function.
        if (node==NULL) {
            return false;
        }
        if (data == node->data) {
            return true;
        }
        else if (data < root->data) {
            return isDataPresent(node->left, data);
        }
        else {
            isDataPresent(node->right, data);
        }
    }

    BinaryTreeNode<int>* insertHelper(BinaryTreeNode<int> *node, int data) {
        if (node==NULL) {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (data <= node->data) {
            node->left = insertHelper(node->left, data);            
        }
        else {
            node->right = insertHelper(node->right, data);
        }
        return node;
    }

    void printHelper(BinaryTreeNode<int> *node) {
        if (node==NULL) {
            return;
        }
        cout << node->data << ":";
        if (node->left) {
            cout << "L:" << node->left->data << ",";
        }
        if (node->right) {
            cout << "R:" << node->left->data;
        }
        cout << endl;
        printHelper(node->left);
        printHelper(node->right);
    }

    BinaryTreeNode<int>* removeHelper(BinaryTreeNode<int>* root, int data) {
        if (root == NULL) {
            return NULL;
        } 
        else if (data < root->data) {
            root->left = removeHelper(root->left, data);
        } 
        else if (data > root->data) {
            root->right = removeHelper(root->right, data);
        } 
        else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            } 
            else if (root->left == NULL) {
                BinaryTreeNode<int>* temp = root->right;
                delete root;
                return temp;
            } 
            else if (root->right == NULL) {
                BinaryTreeNode<int>* temp = root->left;
                delete root;
                return temp;
            } 
            else {
                BinaryTreeNode<int>* minNode = root->right;
                while (minNode->left != NULL) {
                    minNode = minNode->left;
                }
                int rightMin = minNode->data;
                root->data = minNode->data;
                root->right = removeHelper(root->right, rightMin);
                return root;
            }
        }
    }

    public: 

    bool search(int data) {
        return isDataPresent(root, data);
    }

    void insert(int data) {
        root = insertHelper(root, data);
    }

    void remove(int data) {
        root = removeHelper(root, data);
    }

    void print() { 
        printHelper(root);
    }
};