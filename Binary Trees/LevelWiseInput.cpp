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

    void help() {

    }

    ~BinaryTreeNode() {
        delete left;
        delete right;
    }

};

BinaryTreeNode<int> *takeInputLevelWise() {
    int rootData;
    cout << "Enter Root Data: ";
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
    return root;
}

void printLevelWise(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> input;
    input.push(root);
    while (!input.empty()) {
        BinaryTreeNode<int>* front = input.front();
        input.pop();
        cout << front->data << ":";
        if (front->left) {
            cout << "L:" << front->left->data << ",";
            input.push(front->left);
        }
		else {
			cout << "L:-1,";
		}
        if (front->right) {
            cout << "R:" << front->right->data;
            input.push(front->right);
        }
		else {
			cout << "R:-1";
		}
		cout << endl;
    }
}