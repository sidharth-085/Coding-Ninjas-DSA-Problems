#include <iostream>
#include <queue>
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

void zigZagOrder(BinaryTreeNode<int> *root) {
    if (root==NULL) {
        return;
    }
    queue<BinaryTreeNode<int>*> input;
    stack<BinaryTreeNode<int>*> stack;
	input.push(root);

    bool leftToRight = true; // flag to detect order of traversal.
    while (!input.empty()) {
        int size = input.size();
        for (int i=0; i<size; i++) {
            BinaryTreeNode<int> *front = input.front();
            input.pop();
            if (leftToRight) {
                cout << front->data << " ";
            }
            else {
                stack.push(front);
            }

            if (front->left) {
                input.push(front->left);
            }

            if (front->right) {
                input.push(front->right);
            }
        }

        if (!leftToRight) {
            while (!stack.empty()) {
                BinaryTreeNode<int> *reverseData = stack.top();
                cout << reverseData->data << " ";
                stack.pop();
            }
        }
        leftToRight = !leftToRight;
        cout << endl;
    }
}