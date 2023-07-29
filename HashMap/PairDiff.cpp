#include <unordered_map>
using namespace std;

int getPairsWithDifferenceK(int *arr, int size, int diff) {
    std::unordered_map<int, int> seen;
    int countPairs = 0;

    for (int i = 0; i < size; i++) {
        int complement1 = diff + arr[i];
        int complement2 = arr[i] - diff;

        // Check if complement1 exists in the seen map
        if (seen.count(complement1) > 0) {
            countPairs += seen[complement1];
        }

        // Check if complement2 exists in the seen map, excluding the case when diff is 0
        if (seen.count(complement2) > 0 && diff != 0) {
            countPairs += seen[complement2];
        }

        // Increment the frequency of the current element in the seen map
        seen[arr[i]]++;
    }

    return countPairs;
}
