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

Node *removeDuplicates(Node *head) {
	if (head==NULL or head->next==NULL) {
		return head;
	}
	Node *temp = head;
	while (temp->next!=NULL) {
		if (temp->data == temp->next->data) {
			temp->next = temp->next->next;									
		}
		else {
			temp = temp->next;
		}				
	}
	return head;		
}