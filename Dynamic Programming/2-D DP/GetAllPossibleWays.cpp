#include <iostream>
#include <cmath>
using namespace std;

int getAllWaysHelper(int a, int b, int currNum) { // without currSum argument
    if (a == 0) {
        return 1;
    }

    int ways = 0;
    int limit = pow(a, 1.0/b);
    for (int num = currNum + 1; num <= limit; num++) {
        ways = ways + getAllWaysHelper(a - pow(num, b), b, num);
    }
    return ways;
}

int solve(int a, int b, int currSum, int currNum) { // with currSum argument
    if (currSum == a) {
        return 1;
    }

    int ways = 0;
    int limit = pow(a - currSum, 1.0/b);
    for (int i=currNum+1; i <= limit; i++) {
        ways = ways + solve(a, b, currSum + pow(i, b), i);
    }
    return ways;
}

int getAllWaysBF(int a, int b) { // brute force solution
    return getAllWaysHelper(a, b, 0);
    // return solve(a, b, 0, 0);
}

int getAllWaysUsingMemoization(int a, int b, int currSum, int currNum, unordered_map<string, int> &map) {
    // memoization solution
    if (currSum == a) {
        return 1;
    }
	string key = to_string(currSum) + '#' + to_string(currNum);
    if (map.find(key) != map.end()) {
        return map[key];
    }

    int ways = 0;
    int limit = pow(a - currSum, 1.0/b);
    for (int num = currNum + 1; num <= limit; num++) {
        int sum = currSum + pow(num, b);
        ways = ways + getAllWaysUsingMemoization(a, b, sum, num, map);
    }
    map[key] = ways;
    return ways;
}

int getAllWaysMemo(int a, int b) { // memoization solution
    unordered_map<string, int> map;
    // vector<vector<int>> ans(a+1, vector<int>(a+1, -1));  
    return getAllWaysUsingMemoization(a, b, 0, 0, map);
}

// memoization solution: one test case shows runtime error in this.
int getAllWaysUsingMemo(int a, int b, int currSum, int currNum, vector<vector<int>> &ans) {
    if (currSum == a) {
        return 1;
    }

    if (ans[currSum][currNum] != -1) {
        return ans[currSum][currNum];
    }

    int ways = 0;
    int limit = pow(a - currSum, 1.0/b);
    for (int num = currNum + 1; num <= limit; num++) {
        int sum = currSum + pow(num, b);
        ways = ways + getAllWaysUsingMemo(a, b, sum, num, ans);
    }
    ans[currSum][currNum] = ways;
    return ways;
}


int getAllWays(int a, int b) {
    vector<vector<int>> ans(a+1, vector<int>(a+1, -1));
    return getAllWaysUsingMemo(a, b, 0, 0, ans);
}

int getAllWaysHelper(int a, int b, int currNum, int currSum) { // Recursive Solution 
    int result = 0;
    // Calling power of 'i' raised to 'b'
    int p = pow(currNum, b);
    while (p + currSum < a) {
        // Recursively check all greater values of 'i'
        result = result + getAllWaysHelper(a, b, currNum + 1, p + currSum);
        currNum++;
        p = pow(currNum, b);
    }
    /*
    If sum of powers is equal to 'a',
    then increase the value of result
    */
    if (p + currSum == a) {
        result++;
    }
    // Return the final result
    return result;
}

int getAllWays(int a, int b) { // Recursive Solution 
    return getAllWaysHelper(a, b, 1, 0);
}