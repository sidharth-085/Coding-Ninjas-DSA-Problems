#include <iostream>
using namespace std;

void insertionSort(int *arr, int size) {
    for (int i=1; i<size; i++) {
        int current = arr[i];
        int j = i-1;
        while (j>=0 and current < arr[j]) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current;
    }
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    insertionSort(arr, size);
}