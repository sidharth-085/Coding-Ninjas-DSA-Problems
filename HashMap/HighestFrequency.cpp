#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

#include <unordered_map>
int highestFrequency(int arr[], int size) {
    unordered_map<int, int> freq;
    int maxFreq = 0;
    int maxFreqElement = 0;
    for (int i=0; i<size; i++) {
        freq[arr[i]]++;
        if (maxFreq < freq[arr[i]]) {
            maxFreq = freq[arr[i]];
        }        
    }
    for (int i=0; i<size; i++) {
        if (freq[arr[i]] == maxFreq) {
            maxFreqElement = arr[i];
            break;
        }
    }
    return maxFreqElement;
}