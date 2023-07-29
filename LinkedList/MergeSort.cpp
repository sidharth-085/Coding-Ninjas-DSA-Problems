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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    
    Node *head = NULL;
    if (head1->data < head2->data) {
        head = head1;
        head1 = head1->next;
    }
    else {
        head = head2;
        head2 = head2->next;
    }
    
    Node *temp = head;
    while (head1 != NULL and head2 != NULL) {
        if (head1->data < head2->data) {
            temp->next = head1;
            head1 = head1->next;
        }
        else {
            temp->next = head2;
            head2 = head2->next;
        }
        temp = temp->next;
    }
    
    if (head1 != NULL) {
        temp->next = head1;
    }
    else {
        temp->next = head2;
    }
    
    return head;
}

Node* mergeSort(Node *head) {
    if (head==NULL or head->next==NULL) {
        return head;
    }
	// FIND MID NODE
    Node *mid = head;
    Node *fast = head;
    while (fast->next!=NULL and fast->next->next!=NULL) {
        mid = mid->next;
        fast = fast->next->next;
    }

	// DIVIDE THE LINKED LIST INTO 2 PARTS 

    Node *firstHalf = head;
	Node *secondHalf = mid->next;
	mid->next = NULL;

	// CALLING MERGE SORT ON BOTH PARTS

	firstHalf = mergeSort(firstHalf);
	secondHalf = mergeSort(secondHalf);

	// NOW MERGE BOTH SORTED HALVES
    
	Node *finalHead = mergeTwoSortedLinkedLists(firstHalf, secondHalf);
	return finalHead;	
}