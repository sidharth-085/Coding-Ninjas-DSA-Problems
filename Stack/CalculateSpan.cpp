#include <iostream>
#include <stack>
using namespace std;

void calculateSpan(int *input, int size, int *output) {
    stack<int> Stack;
    output[0] = 1;
    Stack.push(0);
    for (int i=1; i<size; i++) {
        while (!Stack.empty() and input[i]>input[Stack.top()]) {
            Stack.pop();
        }
        if (Stack.empty()) {
            output[i] = i+1;
        }
        else {
            output[i] = i-Stack.top();
        }
        Stack.push(i);
    }
}

int main() {

}