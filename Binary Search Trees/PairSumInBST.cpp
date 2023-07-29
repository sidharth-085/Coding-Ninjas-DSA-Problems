#include <iostream>
#include <stack>
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

// METHOD 1: Requires less space but takes more time for large trees.

int countNodes(BinaryTreeNode<int> *root) { // this method only for BST
    if (root==NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    if (root==NULL) {
        return;
    }
    int totalCount = countNodes(root);
    int count = 0;

    stack<BinaryTreeNode<int>*> inOrder;
    stack<BinaryTreeNode<int>*> revInOrder;

    BinaryTreeNode<int> *temp = root;
    while (temp!=NULL) {
        inOrder.push(temp);
        temp = temp->left;
    }

    temp = root;
    while (temp!=NULL) {
        revInOrder.push(temp);
        temp = temp->right;
    }

    while (count < totalCount-1) {
        BinaryTreeNode<int> *inOrderTop = inOrder.top();
        BinaryTreeNode<int> *revInOrderTop = revInOrder.top();
        if (inOrderTop->data + revInOrderTop->data == sum) {
            cout << inOrderTop->data << " " << revInOrderTop->data << endl;

            BinaryTreeNode<int> *top = inOrderTop;
            inOrder.pop();
            count++;
            if (top->right) {
                top = top->right;
                while (top!=NULL) {
                    inOrder.push(top);
                    top = top->left;
                }
            }

            top = revInOrderTop;
            revInOrder.pop();
            count++;
            if (top->left) {
                top = top->left;
                while (top!=NULL) {
                    revInOrder.push(top);
                    top = top->right;
                }
            }
        }
        else if (inOrderTop->data + revInOrderTop->data > sum) {
            BinaryTreeNode<int> *top = revInOrderTop;
            revInOrder.pop();
            count++;
            if (top->left) {
                top = top->left;
                while (top!=NULL) {
                    revInOrder.push(top);
                    top = top->right;
                }
            }
        }
        else {
            BinaryTreeNode<int> *top = inOrderTop;
            inOrder.pop();
            count++;
            if (top->right) {
                top = top->right;
                while (top!=NULL) {
                    inOrder.push(top);
                    top = top->left;
                }
            }
        }
    }
}

// METHOD 2: Requires more space because of vector and less time complexity.

void treeToVector(BinaryTreeNode<int> *root, vector<int> &output) { // Method same for BINARY TREE.
    if (root==NULL) {
        return;
    }
    output.push_back(root->data);
    treeToVector(root->left, output);
    treeToVector(root->right, output);
}

void pairSum(BinaryTreeNode<int> *root, int sum) {
    if (root==NULL) {
        return;
    }
    vector<int> vec;
    treeToVector(root, vec);
    sort(vec.begin(), vec.end());

    int i = 0; 
    int j = vec.size() - 1;
    while (i<j) {
        if (vec[i] + vec[j] == sum) {
            cout << vec[i] << " " << vec[j] << endl;
            i++;
            j--;
        }
        else if (vec[i] + vec[j] < sum) {
            i++;
        }
        else {
            j--;
        }
    }
}