#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseQueue(queue<int> &input) { // Iterative Approach
    if (input.empty()) {
        return;
    }
    stack<int> extra;
    while(!input.empty()) {
        int poppedData = input.front();
        input.pop();
        extra.push(poppedData);
    }
    while (!extra.empty()) {
        int poppedData = extra.top();
        extra.pop();
        input.push(poppedData);
    }
}

void reverseQueue(queue<int> &input) { // Recursive Approach
    if (input.empty()) {
        return;
    }
    int poppedData = input.front();
    input.pop();
    reverseQueue(input); 
    input.push(poppedData);
}