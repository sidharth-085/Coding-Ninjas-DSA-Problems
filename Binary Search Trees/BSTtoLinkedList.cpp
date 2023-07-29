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

template <typename T>
class Node {
    public:
    T data;
    Node *next;

    Node (T data) {
        this->data = data;
        next = NULL;
    }
};

// METHOD 1

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    if (root==NULL) {
        return NULL;
    }
	Node<int> *head = NULL;
    Node<int> *mid = new Node<int>(root->data);
    Node<int> *leftAns = constructLinkedList(root->left);
    Node<int> *rightAns = constructLinkedList(root->right);
    
    // Have to traverse left part till end node.
	if (leftAns) {
		head = leftAns;
		Node<int> *temp = leftAns;
    	while (temp->next!=NULL) {
        	temp = temp->next;
    	}
		temp->next = mid;
    	mid->next = rightAns;
	}
	else {
		head = mid;
		mid->next = rightAns;
	}
	return head;
}    

// METHOD 2

void constructLinkedListHelper(BinaryTreeNode<int>* root, Node<int>* &head, Node<int>* tail) {
    if (root == nullptr) {
        return;
    }
    constructLinkedListHelper(root->left, head, tail);
    Node<int>* newNode = new Node<int>(root->data);
    if (head == nullptr) {
        head = newNode;
    }
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    constructLinkedListHelper(root->right, head, tail);
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
    Node<int>* head = NULL;
    Node<int>* tail = NULL;
    constructLinkedListHelper(root, head, tail);
    return head;
}