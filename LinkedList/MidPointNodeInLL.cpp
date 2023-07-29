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

Node *midPoint(Node *head) {
	if (head==NULL or head->next==NULL) {
		return head;
	}
	Node *slow = head;
	Node *fast = head;
	while (fast->next!=NULL and fast->next->next!=NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}