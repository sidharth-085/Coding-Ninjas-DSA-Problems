#include <vector>
#include <queue>
using namespace std;

#include <vector>
#include <queue>

vector<int> kLargest(int *arr, int size, int k) {
    priority_queue<int, vector<int>, greater<int>> pq; // Create a min priority queue

    // Insert the first k elements into the priority queue
    for (int i = 0; i < k; i++) {
        pq.push(arr[i]);
    }

    // Check if the remaining elements are larger than the top element of the priority queue
    for (int i = k; i < size; i++) {
        if (arr[i] > pq.top()) {
            pq.pop(); // Remove the smallest element from the priority queue
            pq.push(arr[i]); // Insert the larger element into the priority queue
        }
    }

    vector<int> ans;
    // Fill the result vector with the k largest elements from the priority queue
    while (!pq.empty()) {
        ans.push_back(pq.top()); // Add the largest element to the result vector
        pq.pop(); // Remove the largest element from the priority queue
    }

    return ans;
}