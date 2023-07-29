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

class Stack1 {
    Node *head;
    Node *tail;
    int nextIndex;

    public:

    Stack1() {
        head = NULL;
        tail = NULL;
        nextIndex = 0;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        if (head==NULL) {
            head = newNode;
            tail = newNode; 
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        nextIndex++;
    }

    int pop() {
        if (head==NULL) {
            return -1;
        }
        int poppedData = *tail->data;
        if (head==tail) {
            delete tail;
            head = NULL;
            tail = NULL;
        }
        else {
            Node* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            current->next = NULL;
            delete tail;
            tail = current;
        }
        nextIndex--;
        return poppedData;
    }

    bool isEmpty() {
        return head==NULL;
    }

    int top() {
        if (head==NULL) {
            return -1;
        }
        return *tail->data;
    }

    int getSize() {
        return nextIndex;
    }
};

class Stack2 {
    Node *head;
    int size;

    public:

    Stack2() {
        head = NULL;
        size = 0;
    }

    void push(int data) {
        Node *newNode = new Node(data);
        if (head==NULL) {
            head = newNode;
            size = 1;
        }
        else {
            newNode->next = head; 
            head = newNode;
            size++;
        }
    }

    int pop() {
        if (head==NULL) {
            return -1;
        }
        int poppedData = *head->data;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
        return poppedData;       
    }

    bool isEmpty() {
        return head==NULL;
    }

    int top() {
        if (head==NULL) {
            return -1;
        }
    }

    int getSize() {
        return size;
    }
};
