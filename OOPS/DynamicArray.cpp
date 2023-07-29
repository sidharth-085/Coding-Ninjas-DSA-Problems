#include <iostream>
using namespace std;

class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;

    DynamicArray() {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }

    public:

    void add(int element) {
        if (nextIndex==capacity) {
            int *newData = new int[2*capacity];
            for (int i=0; i<nextIndex; i++) {
                newData[i] = data[i];
            }
            delete [] data;
            data = newData;
        }
        data[nextIndex] = element;             
        nextIndex++;   
    }

    int getSize() {
        return nextIndex;
    }

    void addElement(int element, int index) {
        if (index < nextIndex) {
            data[index] = element;
        }
        else if (index > nextIndex) {
            return;
        }
        else {
            add(element);
        }
    }

    void display(int start = 0) {
        for (int i=start; i<nextIndex; i++) {
            cout << data[i] << " ";
        }
    }

    int getElement(int index) {
        if (index < nextIndex) 
            return data[index];
        else 
            return;
    }

    void operator=(DynamicArray arr) {
        data = new int[arr.capacity];
        for (int i=0; i < arr.capacity; i++) {
            data[i] = arr.getElement(i);
        }
        nextIndex = arr.nextIndex;
        capacity = arr.capacity;
    }

};

int main() {

}