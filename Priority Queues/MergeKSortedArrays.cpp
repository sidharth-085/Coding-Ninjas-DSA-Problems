#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    priority_queue<int, vector<int>, greater<int>> pq; // min priority queue
    for (int i=0; i<input.size(); i++) {
        vector<int> *currArray = input[i];
        for (int j=0; j<currArray->size(); j++) {
            pq.push(currArray->at(j));
        }
    }
    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}