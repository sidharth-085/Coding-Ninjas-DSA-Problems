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
            int *newData = new int[2*capacity];
            int j=0;
            for (int i=firstIndex; i<capacity; i++) {
                newData[j] = arr[i];
                j++;
            }
            for (int i=0; i<firstIndex; i++) {
                newData[j] = arr[i];
                j++;
            }
            delete [] arr;
            arr = newData;
            firstIndex = 0;
            nextIndex = capacity;
            capacity = capacity*2;
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
