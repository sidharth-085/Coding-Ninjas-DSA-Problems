#include <iostream>
using namespace std;

class Deque {
    int *queue;
    int front;
    int rear;
    int size;
    int capacity;
    
    public:

    Deque(int capacity) {
        this->capacity = capacity;
        size = 0;
        front = -1;
        rear = 0;
        queue = new int[capacity];
    }

    void insertFront(int element) {
        if (isFull()) {
            cout << "-1" << endl;
            return;
        }

        if (front == -1)
            front = rear = 0;
        else if (front == 0)
            front = capacity - 1;
        else
            front--;

        queue[front] = element;
        size++;
    }

    void insertRear(int element) {
        if (isFull()) {
            cout << "-1" << endl;
            return;
        }

        if (front == -1)
            front = rear = 0;
        else if (rear == capacity - 1)
            rear = 0;
        else
            rear++;

        queue[rear] = element;
        size++;
    }

    void deleteFront() {
        if (isEmpty()) {
            cout << "-1" << endl;
            return;
        }

        if (front == rear)
            front = rear = -1;
        else if (front == capacity - 1)
            front = 0;
        else
            front++;

        size--;
    }

    void deleteRear() {
        if (isEmpty()) {
            cout << "-1" << endl;
            return;
        }

        if (front == rear)
            front = rear = -1;
        else if (rear == 0)
            rear = capacity - 1;
        else
            rear--;

        size--;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return queue[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return queue[rear];
    }

    bool isFull() {
        return size == capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    ~Deque() { // destructor
        delete[] queue;
    }
};