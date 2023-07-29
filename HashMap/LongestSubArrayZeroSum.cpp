#include <unordered_map>
using namespace std;

int lengthOfLongestSubsetWithZeroSum(int* arr, int size) {
    unordered_map<int, int> sumMap;
    int maxLength = 0;

    for (int i = 0; i < size-1; i++) {
        arr[i+1] = arr[i+1] + arr[i];
    }

    for (int i = 0; i < size; i++) {
        // If the current sum is zero, update the maxLength
        if (arr[i] == 0) {
            maxLength = i + 1;
        }
        // If the current sum is already in the map, update the maxLength if needed
        else if (sumMap.count(arr[i]) > 0) {
            maxLength = max(maxLength, i - sumMap[arr[i]]);
        }
        // If the current sum is not in the map, store it along with its index
        else {
            sumMap[arr[i]] = i;
        }
    }

    return maxLength;
}