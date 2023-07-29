#include <string>
#include <iostream>
#include <climits>
using namespace std;

int solveHelper(string str1, string str2, int index1, int index2) { // Brute force Approach 1
    int m = str1.size();
    int n = str2.size();
    
    if (index1 == m) { 
        return 1001;
    }

    if (index2 == n) {
        return 1;
    }

    int option1 = solveHelper(str1, str2, index1 + 1, index2);

    int i;
    for (i = index2; i < n; i++) {
        if (str2[i] == str1[index1]) {
            break;
        }
    }

    if (i == n) {
        return 1;
    }
    
    int option2 = solveHelper(str1, str2, index1 + 1, i + 1) + 1;

    return min(option1, option2);
}

int solve1(string str1, string str2) { // Brute Force Approach 1
    return solveHelper(str1, str2, 0, 0);
}

int solve2(string str1, string str2) { // Brute Force Approach 2
    int m = str1.size();
    int n = str2.size();

    if (m == 0) {
        return 1001;
    }

    if (n == 0) {
        return 1;
    }

    int notIncluded = solve2(str1.substr(1), str2);

    int i;
    for (i = 0; i < n; i++) {
        if (str2[i] == str1[0]) {
            break;
        }
    }

    if (i == n) {
        return 1;
    }

    int included = 1 + solve2(str1.substr(1), str2.substr(i+1));

    return min(included, notIncluded);
}

int solveUsingMemoHelper(string str1, string str2, vector<vector<int>> &ans) {
    int m = str1.size();
    int n = str2.size();

    if (m == 0) {
        return 1001;
    }

    if (n == 0) {
        return 1;
    }

    if (ans[m][n] != -1) {
        return ans[m][n];
    }

    int notIncluded = solveUsingMemoHelper(str1.substr(1), str2, ans);

    int i;
    for (i=0; i<str2.size(); i++) {
        if (str2[i] == str1[0]) {
            break;
        }
    }

    if (i == str2.size()) {
        return 1;
    }

    int included = 1 + solveUsingMemoHelper(str1.substr(1), str2.substr(i+1), ans);

    ans[m][n] = min(included, notIncluded);
    return ans[m][n];
}

int solveUsingMemoization1(string str1, string str2) { // Memoization Approach 1
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> ans(m + 1, vector<int>(m + 1, -1));
    return solveUsingMemoHelper(str1, str2, ans);
}

int solveUsingMemoHelper(string str1, string str2, int index1, int index2, vector<vector<int>> &ans) {
    int m = str1.size();
    int n = str2.size();

    if (index1 == m) { 
        return 1001;
    }

    if (index2 == n) {
        return 1;
    }

    if (ans[index1][index2] != -1) {
        ans[index1][index2];
    }

    int notIncluded = solveUsingMemoHelper(str1, str2, index1 + 1, index2, ans);

    int i;
    for (i = index2; i < n; i++) {
        if (str2[i] == str1[index1]) {
            break;
        }
    }

    if (i == n) {
        return 1;
    }
    
    int included = solveUsingMemoHelper(str1, str2, index1 + 1, i + 1, ans) + 1;
    ans[index1][index2] = min(included, notIncluded);
    return ans[index1][index2];
}

int solveUsingMemoization2(string str1, string str2) { // Memoization Approach 2
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> ans(m+1, vector<int>(n+1, -1));
    return solveUsingMemoHelper(str1, str2, 0, 0, ans);
}

int solveUsingDP1(string str1, string str2) { // DP Approach 1
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> ans(m+1, vector<int>(n+1, 0));

    for (int i=0; i < n + 1; i++) {
        ans[0][i] = 1001;
    }

    for (int i=0; i < m + 1; i++) {
        ans[i][0] = 1;
    }

    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            int notInclude = ans[i-1][j];
            char firstChar= str1[i-1];
            int k;
            for (k = j-1; k >= 0; k--) {
                if (firstChar == str2[k]) {
                    break;
                }
            }
            if (k == -1) {
                ans[i][j] = 1;
            }
            else {
                int include = ans[i-1][k] + 1;
                ans[i][j] = min(include, notInclude);
            }
        }
    }
    return ans[m][n];
}

int solveUsingDP2(string str1, string str2) { // DP Approach 2: Optimized approach of solveUsingDP1.
    int m = str1.size();
    int n = str2.size();

    vector<vector<int>> ans(m+1, vector<int>(n+1, 0));
    vector<vector<int>> next(m+1, vector<int>(n+1, 0));

    for (int i=0; i < m; i++) {
        int prevIndex = -1;
        for (int j=0; j < n; j++) {
            if (str1[i] == str2[j]) {
                prevIndex = j;
            }
            next[i+1][j+1] = prevIndex;
        }
    }

    for (int i=0; i < n + 1; i++) {
        ans[0][i] = 1001;
    }

    for (int i=0; i < m + 1; i++) {
        ans[i][0] = 1;
    }

    for (int i = 1; i < m+1; i++) {
        for (int j = 1; j < n+1; j++) {
            int notInclude = ans[i-1][j];
            if (next[i][j] == -1) {
                ans[i][j] = 1;
            }
            else {
                int include = ans[i-1][next[i][j]] + 1;
                ans[i][j] = min(include, notInclude);
            }
        }
    }
    return ans[m][n];
}

int main() {
    cout << solve1("abc", "aabbccdd") << endl;
    cout << solve2("abc", "aabbccdd") << endl;
    cout << solveUsingMemoization1("abc", "aabbccdd") << endl;
    cout << solveUsingMemoization2("abc", "aabbccdd") << endl;
    cout << solveUsingDP1("abc", "aabbccdd") << endl;
    cout << solveUsingDP2("abc", "aabbccdd") << endl;
}