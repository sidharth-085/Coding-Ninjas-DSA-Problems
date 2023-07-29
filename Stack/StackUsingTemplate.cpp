#include <iostream>
#include <climits>
using namespace std;

template <typename Temp>
// we can use multiple template also
// template <typename Temp, typename Random>
class Stack {
    Temp *arr;
    int nextIndex;
    int capacity;

    public: 

    Stack() {
        arr = new Temp[5];
        nextIndex = 0;
        capacity = 5;
    }

    void push(Temp data) { // only push functions changes, else remains same.
        if (nextIndex==capacity) {
            Temp *newArr = new Temp[2*capacity];
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

    Temp pop() {
        if (nextIndex==0) {
            cout << "Stack is Empty" << endl;
            return 0;
        }
        nextIndex--;
        return arr[nextIndex];
    }

    Temp top() {
        if (nextIndex==0) {
            cout << "Stack is Empty" << endl;
            return 0;
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
    Stack<int> stack1;
    Stack<double> stack;
}