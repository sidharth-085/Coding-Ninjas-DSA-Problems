#include <vector>
#include <unordered_map>
using namespace std;

std::vector<int> longestConsecutiveIncreasingSequence(int *arr, int n) {
    std::unordered_map<int, bool> numMap;
    std::vector<int> result;

    // Insert all elements into the map
    for (int i = 0; i < n; i++) {
        numMap[arr[i]] = true;
    }

    int maxLength = 0;
    int startElement = 0;

    // Traverse each element in the array
    for (int i = 0; i < n; i++) {
        // Check if the current element is the start of a sequence
        if (numMap.count(arr[i] - 1) == 0) {
            int currentElement = arr[i];
            int currentLength = 1;

            // Find the length of the consecutive sequence
            while (numMap.count(currentElement + 1) > 0) {
                currentElement++;
                currentLength++;
            }

            // Update the maximum length and starting element
            if (currentLength > maxLength) {
                maxLength = currentLength;
                startElement = arr[i];
            }
        }
    }

    // Add the first and last element of the consecutive sequence to the result vector
    result.push_back(startElement);
    result.push_back(startElement + maxLength - 1);

    return result;
}
