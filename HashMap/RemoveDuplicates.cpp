#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> removeDuplicates(int *arr, int size) {
    vector<int> output;
    unordered_map<int, bool> seen;
    for (int i=0; i<size; i++) {
        if (seen.count(arr[i]) == 0) {
            output.push_back(arr[i]);
            seen[arr[i]] = true;            
        }
    }
    return output;
}