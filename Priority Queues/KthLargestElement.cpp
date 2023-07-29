#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthLargest(int *arr, int size, int k) {
    priority_queue<int> pq;
    for (int i=0; i<size; i++) {
        pq.push(arr[i]);
    }   
    for (int i=1; i<=k-1; i++) {
        pq.pop();
    }
    return pq.top();
}