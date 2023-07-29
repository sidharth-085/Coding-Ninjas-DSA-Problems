#include <iostream>
using namespace std;

void mergeTwoSortedArrays(int *input1, int size1, int *input2, int size2, int *ans) {
    int i = 0; int j = 0; int z = 0;
    while (i<size1 and j<size2) {
        if (input1[i] < input2[j]) {
            ans[z++] = input1[i++];
        }
        else {
            ans[z++] = input2[j++]; 
        }
    }
    while (i<size1) {
        ans[z++] = input1[i];
    }
    while (j<size2) {
        ans[z++] = input2[j];
    }
}

int main() {
    int size1;
    cin >> size1;
    int input1[size1];
    for (int i=0; i<size1; i++) {
        cin >> input1[i];
    }

    int size2;
    cin >> size2;
    int input2[size2];
    for (int i=0; i<size2; i++) {
        cin >> input2[i];
    }
    
}