#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <climits>
using namespace std;

int countStepsToOne(int n) { // BRUTE FORCE APPROACH
    // Base case: If n is already 1, no steps are needed.
    if (n == 1) {
        return 0;
    }
    // Recursive calls for all three options and finding the minimum steps among them.
    int option1 = countStepsToOne(n - 1);
    int option2 = INT_MAX;
    if (n%2==0) {
        option2 = countStepsToOne(n/2);
    }
    int option3 = INT_MAX;
    if (n%3==0) {
        option3 = countStepsToOne(n/3);
    }
    int minOption = min(option1, min(option2, option3));
    return 1 + minOption;
}

int minStepsUsingMemoizationHelper(int n, int *ans) {
    if (n==1) {
        return 0;
    }

    if (ans[n] != -1) {
        return ans[n];
    }

    int option1 = minStepsUsingMemoizationHelper(n-1, ans);
    int option2 = INT_MAX;
    if (n%2==0) {
        option2 = minStepsUsingMemoizationHelper(n/2, ans);
    }
    int option3 = INT_MAX;
    if (n%3==0) {
        option3 = minStepsUsingMemoizationHelper(n/3, ans);
    }
    int output = min(option1, min(option2, option3)) + 1;
    ans[n] = output;
    return ans[n];
}

int minStepsUsingMemoization(int n) {
    int *ans = new int[n+1]; // can use unordered_map or vector also
    for (int i=0; i<n+1; i++) {
        ans[i] = -1;    
    }
    return minStepsUsingMemoizationHelper(n, ans);
}

int countStepsToOneUsingDp(int n) { // USING DP APPROACH
    // Create a vector to store the minimum steps for each value from 1 to n.
    vector<int> dp(n + 1, 0);

    // Base case: If n is already 1, no steps are needed.
    dp[1] = 0;

    // Iterate from 2 to n, calculating the minimum steps for each value.
    for (int i = 2; i < n+1; i++) {
        // Calculate the minimum steps by considering all three options.
        int option1 = dp[i - 1];
        int option2 = INT_MAX;
        if (i%2==0) {
            option2 = dp[i/2];
        }
        int option3 = INT_MAX;
        if (i%3==0) {
            option3 = dp[i/3];
        }
        int minOption = min(option1, min(option2, option3));
        dp[i] = 1 + minOption;
    }

    // Return the minimum steps required for the input number n.
    return dp[n];
}