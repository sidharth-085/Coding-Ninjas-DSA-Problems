#include <iostream>
#include <climits>
using namespace std;

class Stack {
    int *arr;
    int nextIndex;
    int capacity;

    public: 

    Stack() {
        arr = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    void push(int data) { // only push functions changes, else remains same.
        if (nextIndex==capacity) {
            int *newArr = new int[2*capacity];
            for (int i=0; i<nextIndex; i++) {
                newArr[i] = arr[i];
            }
            delete [] arr;
            arr = newArr;
            capacity = 2*capacity;
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