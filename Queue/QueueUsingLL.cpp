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

class Queue {
	Node *head;
	Node *tail;
	int size;
   public:

    Queue() {
		head = NULL;
		tail = NULL;
		size = 0;
	}
	
	int getSize() {
		return size;
	}

    bool isEmpty() {
		return size==0;
	}

    void enqueue(int data) {
		Node *newNode = new Node(data);
		if (head==NULL) {
			head = newNode;
			tail = newNode;
			size++;
			return;
		}
		tail->next = newNode;
		tail = newNode;
		size++;
	}

    int dequeue() {
    	if (head == NULL || size == 0) {
        	return -1;
		}
    	int poppedData = *head->data;
    	Node *random = head;
    	head = head->next;
    	size--;
    	delete random;
    	if (size == 0) {
        	tail = NULL;
    	}
    	return poppedData;
	}

    int front() {
		if (head==NULL or size==0) {
			return -1;
		}
		return *head->data;
    }
};