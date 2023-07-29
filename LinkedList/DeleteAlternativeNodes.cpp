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

void deleteAlternateNodes(Node *head) {
    if (head==NULL or head->next==NULL) {
        return;
    }
    Node *temp = head->next;
    head->next = temp->next;
    free(temp);
    deleteAlternateNodes(head->next);
}