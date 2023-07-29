#include <iostream>
using namespace std;

class Node {
    public:
    int *data;
    Node *next;

    Node (int data) {
        this->data = new int;
        *(this->data) = data;
        next = NULL;
    }

};

// Approach 1: Using Recursion

Node* reverseLL(Node *head) {
    if (head==NULL or head->next==NULL) {
        return head;
    }
    Node *smallLL = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallLL;
}

Node *kReverse(Node *head, int k) {
	if (head==NULL or k==0 or k==1) {
		return head;
	}
	Node *temp = head;
	int count = 0;
	while (count < k-1 and temp!=NULL) {
		temp = temp->next;
		count++;
	}
	 if (temp == NULL) {
        return reverseLL(head);
    }
	Node *smallAns = kReverse(temp->next, k); // Node *nextNode = temp->next;
	temp->next = NULL;
	Node *newHead = reverseLL(head);
	head->next = smallAns;  // head->next = kReverse(nextNode, k);

	return newHead;
}

// Approach 2: Recursive with Iterative Reverse LL

Node* kReverse(Node *head, int n) {
	if(head == NULL || head->next == NULL){
        return head;
    }
    if (n<=1) {
        return head;
    }
    Node* current = head;
    Node* temp = NULL;
    Node* prev = NULL;
    int count = 0;
    while(current!=NULL and count<n){
        temp = current->next;
        current->next = prev;
        prev = current;
        current = temp;
        count++;
    }
    if(temp != NULL){
        head->next = kReverse(temp,n);
    }
    return prev;
}

