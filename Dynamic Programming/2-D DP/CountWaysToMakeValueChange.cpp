#include <iostream>
using namespace std;

int countWaysToMakeChangeHelperBF(int *input, int size, int value, int currSum, int currIndex) {
    // If the current sum equals the target value, a valid way to make change is found
    if (currSum == value) {
        return 1;
    }

    // If the current index exceeds the size of the denominations array or the current sum exceeds the target value,
    // it is not possible to make change with the given denominations
    if (currIndex == size || currSum > value) {
        return 0;
    }

    // Include the current denomination and recursively call for the remaining value
    int sum = currSum + input[currIndex];
    int includeWays = countWaysToMakeChangeHelperBF(input, size, value, sum, currIndex);

    // Exclude the current denomination and recursively call for the remaining denominations
    int excludeWays = countWaysToMakeChangeHelperBF(input, size, value, currSum, currIndex+1);

    int totalWays = includeWays + excludeWays;
    return totalWays;
}

int countWaysToMakeChangeBF(int denominations[], int numDenominations, int value) {
	return countWaysToMakeChangeHelperBF(denominations, numDenominations, value, 0, 0);
}

int countWaysToMakeChangeHelper(int *input, int size, int value, int currSum, int currIndex, vector<vector<int>> &ans) {
    // If the current sum equals the target value, a valid way to make change is found
    if (currSum == value) {
        return 1;
    }

    // If the current index exceeds the size of the denominations array or the current sum exceeds the target value,
    // it is not possible to make change with the given denominations
    if (currIndex == size || currSum > value) {
        return 0;
    }

    // Check if the result for the current state has already been computed
    if (ans[currSum][currIndex] != -1) {
        return ans[currSum][currIndex];
    }

    int sum = currSum + input[currIndex];
    int includeWays = countWaysToMakeChangeHelper(input, size, value, sum, currIndex, ans);

    int excludeWays = countWaysToMakeChangeHelper(input, size, value, currSum, currIndex + 1, ans);

    ans[currSum][currIndex] = includeWays + excludeWays;

    return ans[currSum][currIndex];
}

int countWaysToMakeChangeMemo(int denominations[], int numDenominations, int value) {
    vector<vector<int>> ans(value + 1, vector<int>(numDenominations + 1, -1));
    return countWaysToMakeChangeHelper(denominations, numDenominations, value, 0, 0, ans);
}

int countWaysToMakeChangeDP(int *denominations, int numDenominations, int value) {
    vector<vector<int>> ans(value + 1, vector<int>(numDenominations + 1, 0));

    // There is one way to make change for the value 0 using no denominations
    for (int i = 0; i < numDenominations + 1; i++) {
        ans[0][i] = 1;
    }

    // Calculate the number of ways to make change for each value from 1 to 'value'
    for (int i = 1; i < value + 1; i++) {
        for (int j = 1; j < numDenominations + 1; j++) {
            int include = 0; 
            int exclude = 0; 

            if (i >= denominations[j-1]) { // include condition
                include = ans[i - denominations[j-1]][j];
            }

            // Exclude the current denomination
            exclude = ans[i][j-1];

            // Total number of ways is the sum of included and excluded ways
            ans[i][j] = include + exclude;
        }
    }
    
    return ans[value][numDenominations];
}