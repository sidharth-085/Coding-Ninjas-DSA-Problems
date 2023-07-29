#include <iostream>
using namespace std;

int staircase(int n) { // Brute Force Approach
    if (n==0 || n==1) {
        return 1;
    }
    if (n==2) {
        return 2;
    }
    int option1 = staircase(n-1);
    int option2 = staircase(n-2);
    int option3 = staircase(n-3);

    int totalWays = option1 + option2 + option3;
    return totalWays;
}

int staircaseUsingMemoizationHelper(int n, int *ans) { // Memoization Approach
    if (n==0 || n==1) {
        return 1;
    }
    if (n==2) {
        return 2;
    }
    if (ans[n] != -1) {
        return ans[n];
    }

    int option1 = staircaseUsingMemoizationHelper(n-1, ans);
    int option2 = staircaseUsingMemoizationHelper(n-2, ans);
    int option3 = staircaseUsingMemoizationHelper(n-3, ans);

    int totalWays = option1 + option2 + option3;
    ans[n] = totalWays;
    return ans[n];
}

int staircaseUsingMemoization(int n) { // Memoization Approach
    int *ans = new int[n+1];
    for (int i=0; i<n+1; i++) {
        ans[i] = -1;
    }
    return staircaseUsingMemoizationHelper(n, ans);
}

int staircaseUsingDP(int n) { // DP solution
    int *ans = new int[n+1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;

    for (int i=3; i<n+1; i++) {
        ans[i] = ans[i-1] + ans[i-2] + ans[i-3];
    }
    return ans[n];
}