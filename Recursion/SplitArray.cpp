#include <iostream>
using namespace std;

// This function recursively checks if it is possible to split the array into two subarrays
// such that the sum of elements in one subarray is divisible by 5 and the sum of elements
// in the other subarray is divisible by 3.
bool helper(int *arr, int size, int sum1, int sum2) {
    // Base case: If the entire array has been traversed,
    // check if the sums of both subarrays are equal.
    if (size == 0) {
        return sum1 == sum2;
    }

    // If the current element is divisible by 5, add it to sum1.
    if (arr[0] % 5 == 0) {
        sum1 = sum1 + arr[0];
    }
    // If the current element is divisible by 3, add it to sum2.
    else if (arr[0] % 3 == 0) {
        sum2 = sum2 + arr[0];
    }
    // If the current element is not divisible by 5 or 3, recursively check two possibilities:
    // 1. Include the current element in sum1.
    // 2. Include the current element in sum2.
    else {
        // Recursively call the helper function for the next element with updated sums.
        bool ans1 = helper(arr+1, size-1, sum1 + arr[0], sum2);
        bool ans2 = helper(arr+1, size-1, sum1, sum2 + arr[0]);

        // If either of the two possibilities is true, return true.
        if (ans1 || ans2) {
            return true;
        }
        // If both possibilities are false, return false.
        return false;
    }

    // Recursively call the helper function for the next element with the same sums.
    return helper(arr+1, size-1, sum1, sum2);
}

// This function checks if it is possible to split the input array into two subarrays
// such that the sum of elements in one subarray is divisible by 5 and the sum of elements
// in the other subarray is divisible by 3.
bool splitArray(int *input, int size) {
    // Call the helper function with initial sums as 0.
    return helper(input, size, 0, 0);
}

int main() {

}