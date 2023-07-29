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

Node *evenAfterOdd(Node *head) {
	Node *temp = head;

	Node *oddHead = NULL;
	Node *oddTail = NULL;	
	Node *evenHead = NULL;	
	Node *evenTail = NULL;	

	while (temp!=NULL) {
		if (*temp->data%2!=0) {
			if (oddHead==NULL) {
				oddHead = temp;
				oddTail = temp;
			}
			else {
				oddTail->next = temp;
				oddTail = temp;
			}
		}
		else {
			if (evenHead==NULL) {
				evenHead = temp;
				evenTail = temp;
			}
			else {
				evenTail->next = temp;
				evenTail = temp;
			}
		}
		temp = temp->next;
	}
	if (oddHead==NULL) {
		return evenHead;
	}
	else {
		oddTail->next = evenHead;
	}
	if (evenHead==NULL) {
		return oddHead;		
	}
	else {
		evenTail->next = NULL;
	}
	return oddHead;
}

int main() {

}