#include <iostream>
using namespace std;

void rotateTheArray(int *arr, int n, int size) {
    int temp[n];
    for (int i=0; i<n; i++) {
        temp[i] = arr[i];
    }
    int j = 0;
    for (int i=0; i<size; i++) {
        if (i<size-n) {
            arr[i] = arr[n+i];
        }
        else {
            arr[i] = temp[j++];
        }
    }
}

int main() {
     int size, n;
     cin >> size;
     int arr[size];
     for (int i=0; i<size; i++) {
      cin >> arr[i];
     }
     cin >> n;
     rotateTheArray(arr, n, size);
}