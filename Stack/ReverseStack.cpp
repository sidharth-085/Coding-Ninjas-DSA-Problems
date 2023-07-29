#include <iostream>
#include <stack>
using namespace std;

void reverseStack(stack<int> &input, stack<int> &extra) { // Iterative Approach
    while (!input.empty()) {
        int poppedData = input.top();
        extra.push(poppedData);
        input.pop();
    }
    input = extra; // we have to store reversed stack back to input.
}

void reverseStack(stack<int> &input, stack<int> &output) { // Recursive Approach
    if (input.empty()) {
        return;
    }
    int poppedData = input.top();
    input.pop();
    output.push(poppedData);
    reverseStack(input, output);
    input = output; // we have to store reversed stack back to input.
}