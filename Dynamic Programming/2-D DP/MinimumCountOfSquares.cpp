#include <iostream>
#include <climits>
using namespace std;

int minCount(int n) { // Brute Force Approach
    if (n<=3) {
        return n;
    }
    int minAns = INT_MAX;
    for (int i=1; i*i <= n; i++) {
        int count = minCount(n - (i*i));
        minAns = min(minAns, count);
    }
    return minAns;
}

int minCountUsingMemoizationHelper(int n, int *ans) { // USING MEMOIZATION TECHNIQUE
    if (n<=3) {
        return n;
    }

    if (ans[n] != -1) {
        return ans[n];
    }

    int minAns = INT_MAX;
    for (int i=1; i*i <= n; i++) {
        int countByRec = minCountUsingMemoizationHelper(n - (i*i), ans);
        minAns = min(minAns, countByRec + 1);
    }

    ans[n] = minAns;
    return ans[n];
}

int minCountUsingMemoization(int n) { // USING MEMOIZATION TECHNIQUE
    int *ans = new int[n+1];
    for (int i=0; i<n+1; i++) {
        ans[i] = -1;
    }
    return minCountUsingMemoizationHelper(n, ans);
}

int minCountUsingDP(int n) { // USING DP APPROACH
    int* ans = new int[n + 1];
    ans[0] = 0; // Base case: 0 squares needed for 0

    for (int i = 1; i <= n; i++) {
        ans[i] = INT_MAX; // Initialize ans[i] to a large value

        for (int j = 1; j * j <= i; j++) {
            // For each perfect square j*j, find the minimum count
            // by comparing ans[i] with ans[i - j*j] + 1
            ans[i] = min(ans[i], ans[i - (j*j)] + 1);
        }
    }
    return ans[n];
}
