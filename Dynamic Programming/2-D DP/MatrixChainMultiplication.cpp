#include <iostream>
#include <climits>
using namespace std;

int helperBF(int *arr, int si, int ei) {
    if (si == ei) { // when only one element in the bracket, no multiplication.
        return 0;
    }

    int minMultiplications = INT_MAX; 
    for (int i = si; i < ei; i++) { // multiplication starts from si to ei-1 (ei is last element in the second bracket.)
        int firstBracket = helperBF(arr, si, i); //  first take si to i elements.
        int secondBracket = helperBF(arr, i+1, ei); // secondly takes i+1 to ei elements.

        int multiplications = firstBracket + secondBracket + arr[si-1]*arr[i]*arr[ei]; 
        // add multiplications operation rule of 3.
        // if (arr[0] * arr[1]) * (arr[1] * arr[2]) ==> (arr[0] * arr[1] * arr[2]).
        minMultiplications = min(minMultiplications, multiplications);
    }

    return minMultiplications;
}

int matrixChainMultiplicationBF(int *arr, int size) {
    int matrixStart = 1; // Matrix starts from 1
    int matrixEnd = size-1; // Matrix ends to size.

    return helperBF(arr, matrixStart, matrixEnd); 
    // we do our solution to assume work on matrix not on array.
}

int helperMemo(int *arr, int si, int ei, vector<vector<int>> &ans) {
    if (si == ei) {
        return 0;
    }

    if (ans[si][ei] != -1) {
        return ans[si][ei];
    }

    int minMultiplications = INT_MAX; 
    for (int i = si; i < ei; i++) { // multiplication starts from si to ei-1 (ei is last element in the second bracket.)
        int firstBracket = helperMemo(arr, si, i, ans); //  first take si to i elements.
        int secondBracket = helperMemo(arr, i+1, ei, ans); // secondly takes i+1 to ei elements.

        int multiplications = firstBracket + secondBracket + arr[si-1]*arr[i]*arr[ei]; 
        // add multiplications operation rule of 3.
        // if (arr[0] * arr[1]) * (arr[1] * arr[2]) ==> (arr[0] * arr[1] * arr[2]).
        minMultiplications = min(minMultiplications, multiplications);
    }

    ans[si][ei] = minMultiplications;
    return minMultiplications;
}

int matrixChainMultiplicationMemo(int *arr, int size) {
    vector<vector<int>> ans(size, vector<int>(size, -1));
    return helperMemo(arr, 1, size-1, ans);
}

int matrixChainMultiplicationDP(int* arr, int size) { // DP Approach
    vector<vector<int>> ans(size, vector<int>(size, 0));

    // for doing operations, there will be minimum 3 sized array
    for (int chainLen = 2; chainLen < size; chainLen++) {
        for (int i = 1; i < size - chainLen + 1; i++) { // starting from 1
            int j = i + chainLen - 1; // this is end

            int minMultiplications = INT_MAX;

            // Iterate over all possible splits between i and j
            for (int k = i; k < j; k++) {
                // Calculate the number of multiplications for the current split
                int multiplications = ans[i][k] + ans[k + 1][j] + arr[i - 1] * arr[k] * arr[j];

                minMultiplications = min(minMultiplications, multiplications);
            }
            ans[i][j] = minMultiplications;
        }
    }
    // Return the minimum number of multiplications for the entire chain
    return ans[1][size-1];
}