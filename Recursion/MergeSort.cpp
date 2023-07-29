#include <iostream>
#include <vector>
using namespace std;

void merge (vector<int> &arr, int si, int mid, int ei) {
    int i = si; int j = mid+1; int k = 0;
    vector<int> newArr(ei-si+1);

    while (i<=mid and j<=ei) {
        if (arr[i] < arr[j]) {
            newArr[k] = arr[i];
            i++;
            k++;
        }
        else {
            newArr[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i<=mid) {
        newArr[k] = arr[i];
        k++;
        i++;
    }

    while (j<=ei) {
        newArr[k] = arr[j];
        k++;
        j++;
    }

    for (int i = si, k = 0; i <= ei; i++, k++) {
        arr[i] = newArr[k];
    }   
}

void mergeSort (vector<int>& arr, int si, int ei) {
    if (si >= ei) {
        return;
    }
    int mid = (si+ei)/2;
    mergeSort(arr, si, mid);
    mergeSort(arr, mid+1, ei);
    merge(arr, si, mid, ei);
}