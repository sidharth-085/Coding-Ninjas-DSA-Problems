#include <iostream>
using namespace std;

// METHOD 1 FOR RETURNING OUTPUT ARRAY, THEN PRINT IN MAIN FILE.

int subset(int input[], int size, int output[][20]) {
    if (size==0) {
        output[0][0] = 0;
        return 1;
    }
    int ans = subset(input+1, size-1, output);
    for (int i=0; i<ans; i++) {
        int sizeOfCurrSubset = output[i][0];
        int sizeOfNewSubset = sizeOfCurrSubset + 1;
        output[i+ans][0] = sizeOfNewSubset;
        output[i+ans][1] = input[0];
        for (int j=2; j<=sizeOfNewSubset; j++) {
            output[i+ans][j] = output[i][j-1];
        }
    }
    return 2*ans;
}

//  METHOD 2 FOR PRINTING IN FUNCTION.

void helper(int *input, int size, int startIndex, int *output, int oSize) {
    if (startIndex == size) {
        for (int i=0; i<oSize; i++) {
            cout << output[i] << " ";
        }
        cout << endl;
        return;
    }
    helper(input, size, startIndex+1, output, oSize);
    int smallOutput[1000]; int smallOutputSize = 0;
    int i=0;
    for (i=0; i<oSize; i++) {
        smallOutput[i] = output[i];
    }
    smallOutput[i] = input[0];
    smallOutputSize = oSize + 1;
    helper(input, size, startIndex+1, smallOutput, smallOutputSize);
}

void printSubsetOfArray(int *input, int size) {
    int output[1000];
    helper(input, size, 0, output, 0);
}