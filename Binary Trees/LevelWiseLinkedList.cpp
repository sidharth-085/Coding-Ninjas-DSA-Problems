#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Node {
    public:
    T data;
    Node<T> *next;

    Node (T data) {
        this->data = data;
        next = NULL;
    }
};

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

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    vector<Node<int>*> ans;
    if (root==NULL) {
        return ans;
    }
    queue<BinaryTreeNode<int>*> input;
    input.push(root);
    while (!input.empty()) {
        int levelSize = input.size();
        Node<int> *head = NULL;
        Node<int> *temp = head;
        for (int i=0; i<levelSize; i++) {
            BinaryTreeNode<int> *front = input.front();
            input.pop();
            if (i==0) {
                head = new Node<int>(front->data);
                temp = head;
            }
            else {
                temp->next = new Node<int>(front->data);
                temp = temp->next;
            }
            if (front->left) {
                input.push(front->left);
            }
            if (front->right) {
                input.push(front->right);
            }
        }
        ans.push_back(head);
    }
    return ans;
}