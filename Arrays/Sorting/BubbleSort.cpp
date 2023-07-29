#include <iostream>
using namespace std;

void bubbleSort1(int *arr, int size) {
    while (size) {
        for (int i=0; i<size-1; i++) {
            if (arr[i] > arr[i+1]) {
                swap(arr[i], arr[i+1]);
            }
        }
        size--;
    }
}

void bubbleSort2(int *input, int size)
{
   for (int i=0; i<size-1; i++) {
       for (int j=0; j<size-i-1; j++) {
           if (input[j] > input[j+1]) {
               int temp = input[j];
               input[j] = input[j+1];
               input[j+1] = temp;
           }
       }   
   }
}

int main() {
    int size;
    cin >> size;
    int arr[size];
    for (int i=0; i<size; i++) {
        cin >> arr[i];
    }
    bubbleSort1(arr, size);
    bubbleSort2(arr, size);
}