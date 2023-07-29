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

void printLevelWise(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> input;
    input.push(root);
    while (!input.empty()) {
        int levelSize = input.size();
        for (int i=0; i<levelSize; i++) {
            BinaryTreeNode<int> *frontNode = input.front();
            cout << frontNode->data << " ";
            input.pop();
            if (frontNode->left) {
                input.push(frontNode->left);
            }
            if (frontNode->right) {
                input.push(frontNode->right);
            }
        }
        cout << endl;
    }
}

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> input;
    input.push(root);
    input.push(NULL);
    while (!input.empty()) {
        BinaryTreeNode<int> *frontNode = input.front();
        input.pop();
        if (frontNode==NULL) {
            cout << endl;
            if (!input.empty()) {
                input.push(NULL);
            }
        }
        else {
            cout << frontNode->data << " ";
            if (frontNode->left) {
                input.push(frontNode->left);
            }
            if (frontNode->right) {
                input.push(frontNode->right);
            }
        }
    }
}