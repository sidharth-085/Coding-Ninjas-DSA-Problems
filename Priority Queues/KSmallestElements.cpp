#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#include <vector>
#include <queue>

vector<int> kSmallest(int *arr, int size, int k) {
    priority_queue<int> pq;

    // Insert the first k elements into the priority queue
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Check if the remaining elements are smaller than the top element of the priority queue
    for (int i = k; i < size; i++) {
        if (arr[i] < pq.top()) {
            pq.pop(); // Remove the largest element from the priority queue
            pq.push(arr[i]); // Insert the smaller element into the priority queue
        }
    }

    vector<int> ans;
    // Fill the result vector with the k smallest elements from the priority queue
    while (!pq.empty()) {
        ans.push_back(pq.top()); // Add the smallest element to the result vector
        pq.pop(); // Remove the smallest element from the priority queue
    }
    
    return ans;
}
