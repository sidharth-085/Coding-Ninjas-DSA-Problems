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

int length (Node *head) {
    if (head==NULL) {
        return 0;
    }
    return length(head->next) +1;
}

Node *appendLastNToFirst(Node *head, int n) {
    Node *temp = head;
    Node *lastNode = head;
    int posIndex = length(head) - n;
    int count = 0;
    while (lastNode->next!=NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = head;
    while (count < posIndex-1) {
        temp = temp->next;
        count++;
    }
    head = temp->next;
    temp->next = NULL;  
    return head;
}