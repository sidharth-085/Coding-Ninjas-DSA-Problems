#include <iostream>
using namespace std;

// METHOD 1 Returning the output array.

int helper(int *input, int size, int output[][50], int sum, int si) {
    if (si==size) {
        if (sum==0) {
            output[0][0] = 0;
            return 1;
        }
        else {
            return 0;
        }
    }
    int smallOutput1[500][50]; 
    int size1 = helper(input, size, smallOutput1, sum, si+1);
    int smallOutput2[500][50];
    int size2 = helper(input, size, smallOutput2, sum - input[si], si+1);

    int k = 0;
    for (int i=0; i<size1; i++) {
        for (int j=0; j<=smallOutput1[i][0]; j++) {
            output[k][j] = smallOutput1[i][j];
        }
        k++;
    }
    for (int i=0; i<size2; i++) {
        output[k][0] = smallOutput2[i][0] + 1;
        output[k][1] = input[si];
        for (int j=2; j<=smallOutput2[i][0]; j++) {
            output[k][j] = smallOutput2[i][j-1];           
        }
        k++;
    }
    return k;
}

int subsetSumToK(int *input, int size, int output[][50], int sum) {
    return helper(input, size, output, sum, 0); 
}

// METHOD 2 PRINTING THE SUBSETS SUM TO K

void helperSubsetSumToK(int *input, int size, int si, int *output, int oSize, int sum) {
    if (si==size) {
        if (sum==0) {
            for (int i=0; i<oSize; i++) {
                cout << output[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    helperSubsetSumToK(input, size, si+1, output, oSize, sum);
    int smallOutput[oSize+1];
    if (sum>0) {
        int i=0;
        for (i=0; i<oSize; i++) {
            smallOutput[i] = output[i];
        }
        smallOutput[i] = input[si];
        helperSubsetSumToK(input, size, si+1, smallOutput, oSize+1, sum-input[si]);
    }
    
}
 
void printSubsetSumToK(int *input, int size, int sum) {
    int output[500];
    helperSubsetSumToK(input, size, 0, output, 0, sum);
}

// METHOD 3: THIS METHOD ONLY RETURNS THE COUNT OF SUBSETS.

int solve(int* arr, int size, int k, int startIndex, int currentSum) {
 // solve(int* arr, int size, int startIndex, int currentSum)
    if (startIndex == size) {
        if (currentSum == k) {
            return 1;
        }
        return 0;
    }

    int option1 = solve(arr, size, k, startIndex +1, currentSum + arr[startIndex]);
    int option2 = solve(arr, size, k, startIndex +1, currentSum);

    // int option1 = solve(arr, size, startIndex +1, currentSum - arr[startIndex]);
    // int option2 = solve(arr, size, startIndex +1, currentSum);

    return option1 + option2;
}

int subsetSumToK(int *arr, int size, int k) {
    return solve(arr, size, k, 0, 0);
    // return solve(arr, size, 0, k);
    
    // here we can only pass solve(arr, size, 0, k) this, if we take currentSum - arr[startIndex]
    // instead of currentSum + arr[startIndex] so everytime when current sum decreases, it
    // it finally becomes zero at the case when we found the subset having sum to k.
}

int main() {
    int testCase;
    cin >> testCase;

    for (int i=0; i<testCase; i++) {
        int size;
        cin >> size;

        int k;
        cin >> k;

        int arr[size];
        for (int i=0; i<size; i++) {
            cin >> arr[i];
        }

        int ans = subsetSumToK(arr, size, k);
        cout << ans << endl;
    }
    return 0;
}