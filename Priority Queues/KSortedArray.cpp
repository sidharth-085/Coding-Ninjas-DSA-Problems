#include <iostream>
#include <queue>
using namespace std;

void kSortedArray(int *arr, int size, int k) { // descending order sorting
    // Create a priority queue (min heap)
    priority_queue<int> pq;

    // Insert the first k elements into the priority queue
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Fill the array in descending order by popping elements from the priority queue
    int j = 0; // Index to track the position in the array
    for (int i = k; i < size; i++) {
        arr[j] = pq.top(); // Store the minimum element in the array
        pq.pop(); // Remove the minimum element from the priority queue
        pq.push(arr[i]); // Push the current element into the priority queue
        j++; // Move to the next position in the array
    }

    // Fill the remaining elements from the priority queue into the array
    while (!pq.empty()) {
        arr[j] = pq.top(); // Store the minimum element in the array
        pq.pop(); // Remove the minimum element from the priority queue
        j++; // Move to the next position in the array
    }
}
