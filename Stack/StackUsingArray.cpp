#include <iostream>
#include <climits>
using namespace std;

class Stack {
    int *arr;
    int nextIndex;
    int capacity;

    public: 

    Stack(int size) {
        arr = new int[size];
        nextIndex = 0;
        capacity = size;
    }

    void push(int data) {
        if (nextIndex==capacity) {
            cout << "Stack is Full" << endl;
            return;
        }
        arr[nextIndex] = data;
        nextIndex++;
    }

    int pop() {
        if (nextIndex==0) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return arr[nextIndex];
    }

    int top() {
        if (nextIndex==0) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return arr[nextIndex-1];
    }

    int getSize() {
        return nextIndex;
    }

    bool isEmpty() {
        return nextIndex==0;
    }
};
int main() {

}