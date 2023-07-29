#include <iostream>
using namespace std;

class Queue {
    int *arr;
    int currentSize;
    int nextIndex;
    int firstIndex;
    int capacity;

    public: 

    Queue(int totalSize) {
        arr = new int[totalSize];
        currentSize = 0;
        nextIndex = 0;
        firstIndex = -1;
        capacity = totalSize;
    }

    void enqueue(int data) {
        if (currentSize==capacity) {
            return;
        }
        if (firstIndex==-1) {
            firstIndex = 0;          
        }
        if (nextIndex==capacity) {
            nextIndex = 0;
        }
        arr[nextIndex] = data;
        nextIndex++;
        currentSize++;
    }

    int dequeue() {
        if (firstIndex==capacity) {
            firstIndex = 0;
        }
        int poppedData = arr[firstIndex];
        firstIndex++;
        currentSize--;
        if (currentSize==0) {
            firstIndex = -1;
            nextIndex = 0;
        }
        return poppedData;
    }

    int front() {
        if (currentSize==0) {
            return 0;
        }
        return arr[firstIndex];
    }

    bool isEmpty() {
        return currentSize==0;
    }

    int getSize() {
        return currentSize;
    }
};

int main() {
    Queue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);


	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;
	cout << q.dequeue() << endl;

	cout << q.getSize() << endl;
	cout << q.isEmpty() << endl;
}
