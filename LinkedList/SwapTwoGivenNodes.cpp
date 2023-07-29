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

Node* swapNodes(Node *head, int i, int j) {
    if (i==j) {
        return head;
    }
    int count = 0;
    Node *prev1 = NULL;
    Node *curr1 = head;
    while (curr1!=NULL and count <= i - 1) {
        prev1 = curr1;
        curr1 = curr1->next;
        count++; 
    }
    count = 0;
    Node *prev2 = NULL;
    Node *curr2 = head;
    while (curr2!=NULL and count <= j - 1) {
        prev2 = curr2;
        curr2 = curr2->next;
        count++; 
    }

    if (curr1==NULL or curr2==NULL) {
        return head;
    }
    
    if (prev1==NULL) {
        head = curr2;
    }
    else {
        prev1->next = curr2;
    }
    if (prev2==NULL) {
        head = curr1;
    }
    else {
        prev2->next = curr1;
    }
    Node *temp = curr2->next;
    curr2->next = curr1->next;
    curr1->next = temp;
    return head;
}

int main() {

}