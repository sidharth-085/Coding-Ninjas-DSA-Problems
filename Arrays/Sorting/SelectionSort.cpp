#include <iostream>
#include <climits>
using namespace std;

void swapElements(int *arr, int start, int end) {
    int min = arr[start];
    int minIndex = start;
    for (int i=start+1; i<=end; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    swap(arr[minIndex], arr[start]);
}

void selectionSort(int *arr, int size) {
    int start = 0;
    int end = size-1;
    while(start<=end) {
        swapElements(arr, start, end);
        start++;
    }
} 

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    selectionSort(arr, size);
}