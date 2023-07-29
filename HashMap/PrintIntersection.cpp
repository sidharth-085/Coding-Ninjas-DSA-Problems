#include <iostream>
#include <unordered_map>
using namespace std;

void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> seen;
    for (int i=0; i<n; i++) {
        seen[arr1[i]]++;
    }            
    for (int i=0; i<m; i++) {
        if (seen[arr2[i]] > 0) {
            cout << arr2[i] << endl;
            seen[arr2[i]]--;
        }
    } 
}