#include <iostream>
using namespace std;

bool isMaxHeap(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        int leftChildIndex = 2 * i + 1;
        int rightChildIndex = 2 * i + 2;

        // Check if the left child index is within the size of the array
        if (leftChildIndex < size) {
            // Compare the current element with the left child
            if (arr[i] < arr[leftChildIndex]) {
                return false;
            }
        }

        // Check if the right child index is within the size of the array
        if (rightChildIndex < size) {
            // Compare the current element with the right child
            if (arr[i] < arr[rightChildIndex]) {
                return false;
            }
        }
    }
    return true;
}