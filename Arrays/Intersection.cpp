#include <iostream>
using namespace std;

void intersection(int *arr1, int *arr2, int size1, int size2) {
    sort (arr1, arr1+size1);
    sort (arr2, arr2+size2);

    int i=0; int j=0; int k=0;
    while (i<size1 and j<size2) {
        if (arr1[i]==arr2[j]) {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
}