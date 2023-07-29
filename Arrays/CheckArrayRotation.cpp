#include <iostream>
using namespace std;

int checkArrayRotation(int *arr, int size) {
    int ans = 0;
    for (int i=0; i<size-1; i++) {
        if (arr[i] > arr[i+1]) {
            ans++;
            return ans;
        }
        else {
            ans++;
        }
    }
}

int main() {
     int n;
     cin >> n;
     
     int arr[n];
    
     for (int i=0; i<n; i++) {
      cin >> arr[i];
     }
     
     int rotation = checkArrayRotation(arr, n);
     cout << "Rotation: " << rotation << endl;
}