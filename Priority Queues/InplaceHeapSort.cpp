#include <algorithm>
using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void heapSortAscending(int *arr, int size) {
    if (size==0 or size==1) {
        return;
    }

    // used same array as heap, which acts as COMPLETE BINARY TREE WITH HEAP ORDER (MIN).

    for (int i=1; i<size; i++) {
        int childIndex = i;
        int parentIndex = (childIndex - 1)/2;
        while (childIndex > 0 && arr[childIndex] > arr[parentIndex]) {
            swap(arr[childIndex], arr[parentIndex]);

            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        }
    }

    // now its time to sort the array completely by using removeMin approach.

    int n = size;
    while (n > 1) {
        swap(arr[0], arr[n-1]);
        n--;

        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;  

        while (leftChildIndex < n) {
            int maxIndex = parentIndex;

            if (arr[leftChildIndex] > arr[maxIndex]) {
                maxIndex = leftChildIndex;
            }
            if (arr[rightChildIndex] > arr[maxIndex] && rightChildIndex < n) {
                maxIndex = rightChildIndex;
            }
            if (maxIndex == parentIndex) {
                break;
            }

            swap(arr[maxIndex], arr[parentIndex]);

            parentIndex = maxIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }      
    }
}

void heapSortDescending(int *arr, int size) {
    if (size==0 or size==1) {
        return;
    }

    // used same array as heap, which acts as COMPLETE BINARY TREE WITH HEAP ORDER (MIN).

    for (int i=1; i<size; i++) {
        int childIndex = i;
        int parentIndex = (childIndex - 1)/2;
        while (childIndex > 0 && arr[childIndex] < arr[parentIndex]) {
            swap(arr[childIndex], arr[parentIndex]);

            childIndex = parentIndex;
            parentIndex = (childIndex - 1)/2;
        }
    }

    // now its time to sort the array completely by using removeMin approach.

    int n = size;
    while (n > 1) {
        swap(arr[0], arr[n-1]);
        n--;

        int parentIndex = 0;
        int leftChildIndex = 1;
        int rightChildIndex = 2;  

        while (leftChildIndex < n) {
            int minIndex = parentIndex;

            if (arr[leftChildIndex] < arr[minIndex]) {
                minIndex = leftChildIndex;
            }
            if (arr[rightChildIndex] < arr[minIndex] && rightChildIndex < n) {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex) {
                break;
            }

            swap(arr[minIndex], arr[parentIndex]);

            parentIndex = minIndex;
            leftChildIndex = 2*parentIndex + 1;
            rightChildIndex = 2*parentIndex + 2;
        }      
    }
}