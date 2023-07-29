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

int findNode(Node *head, int n) { // Recursive Method
    if (head==NULL) {
        return -1;
    }
    if (*(head->data) == n) {
        return 0;
    }
    int ans = findNode(head->next, n);
    if (ans!=-1) {
        return ans+1;
    }
    return ans;
}

int findNodeRec(Node *head, int n) { // Recursive Method
	if (head==NULL) {
		return -1;
	}
	int pos = findNodeRec(head->next, n);
	if (pos!=-1) {
		return pos+1;
	}
	else {
		if (*head->data==n) {
			return 0;
		}
		else {
			return pos;
		}
	}
}

int findNode(Node *head, int n) { // Iterative Method
    if (head==NULL) {
        return -1;
    }
    int count = 0;
    while (head!=NULL) {
        if (*head->data==n) {
            return count;
        }
        head = head->next;
        count++;
    }
    return -1;
}