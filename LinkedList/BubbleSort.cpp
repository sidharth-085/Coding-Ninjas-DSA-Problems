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
int length(Node *head) {
    int len = 0;
    Node *temp = head;
    while (temp!=NULL) {
        temp = temp->next;
        len++;
    }
    return len;
}

Node* bubbleSort(Node* head) {
    if (head==NULL or head->next==NULL) {
        return head;
    }
    int len = length(head);

    for (int i=0; i<len; i++) {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next!=NULL) {
            if (temp->data > temp->next->data) {
                if (prev==NULL) {
                    head = temp->next;
                    temp->next = head->next;
                    head->next = temp;
                    prev = head;
                }
                else {
                    Node *node = temp->next->next;
                    temp->next->next = temp;
                    prev->next = temp->next;
                    temp->next = node;
                    prev = prev->next;                   
                }                            
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }   
    }
    return head;
}