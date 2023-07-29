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

int length1(Node *head) { // Iterative Method
    int count = 0;
    Node *temp = head;
    while (temp!=NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int length2(Node *head) { // Recursive Call
	if (head==NULL) {
		return 0;
	}
	int len = length2(head->next);
	return len+1;
}