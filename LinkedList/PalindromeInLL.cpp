#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;

    Node (int data) {
        this->data = data;
        next = NULL;
    }

};

/******************************

int length(Node *head) { // Recursive Call
	if (head==NULL) {
		return 0;
	}
	int len = length(head->next);
	return len+1;
}

bool isPalindrome(Node *head) { // array approach O(n).
    int size = length(head);
    int *arr = new int[size];
    int i=0;
    while (head!=NULL) {
        arr[i++] = *head->data;
        head = head->next;
    }
    for (int i=0; i<size; i++) {
        if (arr[i]!=arr[size-i-1]) {
            return false;          
        }
    }
    return true;
}

Node* reverseLL(Node *head) {
    if (head==NULL or head->next==NULL) {
        return head;
    }
    Node *smallLL = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallLL;
}

Node* makeCopyOfLL(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* newHead = new Node(head->data);
    Node* temp = newHead;
    Node* current = head->next;
    while (current != NULL) {
        Node* newNode = new Node(current->data);
        temp->next = newNode;
        temp = temp->next;
        current = current->next;
    }
    return newHead;
}

bool checkIsPalindrome(Node *head) {
    Node *temp = head;
    Node *copiedHead = makeCopyOfLL(head);
    Node *reversedHead = reverseLL(copiedHead);
    while (temp!=NULL) {
        if (temp->data != reversedHead->data) {
            return false;
        } 
        temp = temp->next;
        reversedHead = reversedHead->next;
    }
    return true;
}

**************************/

Node* reverseLL(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

bool isPalindrome(Node* head) { // best approach
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node* slow = head;
    Node* fast = head;

    // Find the middle node of the linked list
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Reverse the second half of the linked list
    Node* secondHalf = reverseLL(slow->next);
    Node* firstHalf = head;

    // Compare the first half with the reversed second half
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data) {
            return false;
        }
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}


int main() {

}