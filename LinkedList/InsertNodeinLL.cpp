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

Node* insertNodeInLL(Node *head, int data, int i) { // Iterative Method
    int count = 0;
    Node *newNode = new Node(data);
    if (head==NULL) {
        head = newNode;
        return head;
    }
    if (i==0) {
        newNode->next = head;
        head = newNode;
        return head;        
    }
    Node *temp = head;
    while (temp!=NULL and count<i-1) {
        temp = temp->next;
        count++;
    }
    if (temp!=NULL) {
        Node *temp = temp->next;
        temp = newNode;
        newNode->next = temp;
    }
    return head;
}

Node* insertNodeInLL(Node *head, int data, int i) { // Recursive Method
    if (head==NULL) {
        return head;
    }
    if (i==0) {
        Node *newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    head->next = insertNodeInLL(head->next, data, i-1);
    return head;
}
