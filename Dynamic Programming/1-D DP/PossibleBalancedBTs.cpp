#include <iostream>
#include <cmath>
using namespace std;

const int mod = pow(10, 9) + 7;

int balancedBTs(int height) { // Brute Force Approach
    if (height == 0 || height == 1) {
        return 1;
    }

    int count1 = balancedBTs(height - 1);
    int count2 = balancedBTs(height - 2);

    int case1 = int((long(count1)*count1) % mod);
    // case 1: When height of both left & right subtrees is equal i.e. h-1 and diff is 0.
    int case2 = int((long(count1)*count2*2) % mod);
    // case 2: When height of left subtree is h-1 and right subtree is h-2 and diff is 1.
    // case 3: When height of left subtree is h-2 and right subtree is h-1 and diff is 1.

    int ans = (case1 + case2) % mod;
    // by taking modulus with variable mod, the ans lies in the range of integer.
    return ans;
}

int balancedBTsUsingMemoizationHelper(int height, int *ans) { // USING MEMOIZATION APPROACH
    if (height == 0 || height == 1) {
        return 1;
    }

    if (ans[height] != -1) {
        return ans[height];
    }
    
    int count1 = balancedBTs(height - 1);
    int count2 = balancedBTs(height - 2);

    int case1 = int((long(count1)*count1) % mod);
    // case 1: When height of both left & right subtrees is equal i.e. h-1 and diff is 0.
    int case2 = int((long(count1)*count2*2) % mod);
    // case 2: When height of left subtree is h-1 and right subtree is h-2 and diff is 1.
    // case 3: When height of left subtree is h-2 and right subtree is h-1 and diff is 1.

    int finalCount = (case1 + case2) % mod;
    // by taking modulus with variable mod, the ans lies in the range of integer.

    ans[height] = finalCount;
    return ans[height];
}

int balancedBTsUsingMemoization(int height) { // USING MEMOIZATION APPROACH
    int *ans = new int[height + 1];
    for (int i=0; i<height + 1; i++) {
        ans[i] = -1;
    }
    return balancedBTsUsingMemoizationHelper(height, ans);
}

int balancedBTsUsingDP(int height) { // DP APPROACH
    int *ans = new int[height + 1];
    ans[0] = 1;
    ans[1] = 1;

    for (int i=2; i<height+1; i++) {
        int count1 = ans[i-1];
        int count2 = ans[i-2];

        int case1 = int((long(count1)*count1) % mod);
        // case 1: When height of both left & right subtrees is equal i.e. h-1 and diff is 0.
        int case2 = int((long(count1)*count2*2) % mod);
         // case 2: When height of left subtree is h-1 and right subtree is h-2 and diff is 1.
        // case 3: When height of left subtree is h-2 and right subtree is h-1 and diff is 1.

        int finalCount = (case1 + case2) % mod;
        // by taking modulus with variable mod, the ans lies in the range of integer.

        ans[i] = finalCount;
    }
    return ans[height];
}