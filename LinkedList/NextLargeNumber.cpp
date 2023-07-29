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

Node* reverseLL(Node *head) {
    if (head==NULL or head->next==NULL) {
        return head;
    }
    Node *smallLL = reverseLL(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallLL;
}

Node* NextLargeNumber(Node *head) {
    head = reverseLL(head);
    int carry = 1;
    Node *temp = head;
    while (temp!=NULL) {
        *temp->data = *temp->data + carry;
        carry = 0;
        if (*temp->data==10) {
            *temp->data = 0;
            if (temp->next==NULL) {
                Node *newNode = new Node(1);
                temp->next = newNode;            
            }
            else {
                carry = 1;
            }
        }
        temp = temp->next;
    }
    return reverseLL(head);             
}

Node* NextLargeNumber(Node *head) {
    head = reverseLL(head);
    Node *temp = head;
    Node *prev = NULL;
    int carry = 1;
    while (temp!=NULL) {
        *temp->data = (*temp->data + carry)%10;
        carry = (*temp->data + carry)/10;
        prev = temp;
        temp = temp->next;
    }
    if (carry>0) {
        Node *newNode = new Node(1);
        prev->next = newNode;
    }
    return reverseLL(head);
}

// Both Codes are equally optimized because both have O(n) time complexity.
// But, 2nd method is little more optimized.