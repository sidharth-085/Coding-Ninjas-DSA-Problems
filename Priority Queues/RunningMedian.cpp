#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Brute Force Approach

void findMedian(int *arr, int size) {
    for (int i=0; i<size; i++) {
        sort(arr, arr+i+1); // sort everytime when you add an element to the stream.
        if ((i+1)%2 == 0) {
            int first = arr[(i+1)/2];
            int second = arr[((i+1)/2) - 1];

            int avg = (first + second)/2;
            cout << avg << " "; 
        }  
        else {
            cout << arr[(i+1)/2] << " ";
        }
    }
}

// Optimal Approach using Heaps
// Time Complexity : O(N) & Space Complexity : O(N) due to heaps

void findMedian(int *arr, int size) {
    priority_queue<int> maxHeap; // max heap to store smaller numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; // min heap to store larger numbers

    for (int i = 0; i < size; i++) {
        // Step 1: Insert the number into the appropriate heap
        if (maxHeap.empty() || arr[i] < maxHeap.top()) {
            maxHeap.push(arr[i]);                       
        }
        else {
            minHeap.push(arr[i]); 
        }

        // Step 2: Balance the heaps if the size difference becomes more than 1
        if (abs((int)maxHeap.size() - (int)minHeap.size()) > 1) {
            if (maxHeap.size() > minHeap.size()) {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        // Step 3: Calculate and print the median
        int median = 0;
        if (maxHeap.size() == minHeap.size()) {
            median = (maxHeap.top() + minHeap.top()) / 2;
        } 
        else if (maxHeap.size() > minHeap.size()) {
            median = maxHeap.top();
        } 
        else {
            median = minHeap.top();
        }

        cout << median << " ";
    }
}