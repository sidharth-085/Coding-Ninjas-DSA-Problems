#include <iostream>
#include <unordered_map>
using namespace std;

int tripletSum(int *arr, int size, int sum) {
    int count = 0;

    for (int i=0; i<size; i++) {
        unordered_map<int, int> freq;

        int currentSum = sum - arr[i];

        for (int j=i+1; j<size; j++) {
            int complement = currentSum - arr[j];
            if (freq.find(complement) != freq.end()) {
                count = count + freq[complement];
            }
            freq[arr[j]]++;
        }
    }
    return count;
}