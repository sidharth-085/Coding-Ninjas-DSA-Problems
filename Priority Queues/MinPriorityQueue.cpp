#include <vector>
using namespace std;

class PriorityQueue {
    // internally we have priority_queue<int, vector<int>, greater<int>> to use min pq.
    vector<int> pq;

    public:

    bool isEmpty() {
        return pq.size() == 0;
    }

    int getMin() {
        if (isEmpty()) {
            return -1; // states that priority queue is empty.
        }
        return pq[0];
    }

    int getSize() {
        return pq.size();
    }

    void insert(int element) {
        pq.push_back(element);

        int childIndex = pq.size() - 1;
        int parentIndex = (childIndex - 1)/2;
        while (childIndex > 0 && pq[childIndex] < pq[parentIndex]) {
            swap(pq[childIndex], pq[parentIndex]);

            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        }        
    }

    int removeMin() {
        if (isEmpty()) {
            return -1;
        }
        int ans = pq[0];
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;
        while (leftChildIndex < pq.size()) {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex]) {
                minIndex = leftChildIndex;
            }  
            if (pq[minIndex] > pq[rightChildIndex] && rightChildIndex < pq.size()) {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }
            swap(pq[minIndex], pq[parentIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }
        return ans;
    }
};