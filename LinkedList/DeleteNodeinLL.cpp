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

Node *deleteNode(Node *head, int pos) { // Iterative Method
	Node *temp = head;
	int count = 0;
	if (head==NULL) {
		return head;
	}
	if (pos==0) {
		return temp->next;
	}
	while (temp!=NULL and count < pos-1) {
		temp = temp->next;
		count++;
	}
	if (temp==NULL or temp->next==NULL) {
		return head;
	}
	if (temp!=NULL) {
		temp->next = temp->next->next;
		return head;
	}
}

Node* deleteNode(Node *head, int i) { // Recursive Method
    if (head==NULL) {
        return head;
    }
    if (i==0) {
        return head->next;
    }
    head->next = deleteNode(head->next, i-1);
    return head;
}

int main() {

}