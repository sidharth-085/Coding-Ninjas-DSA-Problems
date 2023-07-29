#include <iostream>
#include <climits>
using namespace std;

int findSecondLargest(int *arr, int size) {
    int secondMax = INT_MIN;
    int max = INT_MIN;

    for (int i=0; i<size; i++) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        }
        else if (arr[i] > secondMax and arr[i] < max) {
            secondMax = arr[i];
        }
    }
    return secondMax;
}

int main() {
     int n;
     cin >> n;
     
     int arr[n];
    
     for (int i=0; i<n; i++) {
      cin >> arr[i];
     }

     int secondLargest = findSecondLargest(arr, n);
     cout << "Second Largest Element in Array is : " << secondLargest << endl;
}