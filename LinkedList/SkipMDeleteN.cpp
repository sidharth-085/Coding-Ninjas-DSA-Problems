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

Node* skipMdeleteN(Node *head, int skip, int del) {
    if (head==NULL or skip==0) {
        return NULL;
    }
    if (del==0) {
        return head;
    }
    Node *temp = head;
    int count = 0;
    while (temp!=NULL) {
        count = 0;
        while (count < skip-1 and temp!=NULL) {
            temp = temp->next;
            count++;
        }
        if (temp==NULL) {
            return head;
        }
        count = 0;
        Node *nextNode = temp->next;
        while (nextNode!=NULL and count <= del-1) {
            nextNode = nextNode->next;
            count++;
        }
        temp->next = nextNode;
        temp = nextNode;
    }
    return head;
}