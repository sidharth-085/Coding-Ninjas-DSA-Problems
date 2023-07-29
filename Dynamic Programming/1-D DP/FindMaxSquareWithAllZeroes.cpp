#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int helperBF1(int **arr, int n, int m, int i, int j) { 
    // This is bottom to top approach, we are taken up, left and diagonal element as 
    // parameters to decide matrix size at ans[i][j].
    if (i < 0 || j < 0 || arr[i][j] == 1) {
        return 0;
    }

    int diagonalElement = helperBF1(arr, n, m, i-1, j-1); // call for diagonal element.
    int prevRowElement = helperBF1(arr, n, m, i-1, j); // call for upward element.
    int prevColElement = helperBF1(arr, n, m, i, j-1); // call for left element.

    int ans = 1 + min(diagonalElement, min(prevRowElement, prevColElement));
    // which one is minimum we can take that as the square and add one 0 it.
    return ans;
}

int helperBF2(int **arr, int n, int m, int i, int j) {
    // This is top to bottom approach, we are taken down, right and diagonal element as 
    // parameters to decide matrix size at ans[i][j].
    if (i >= n || j >= m || arr[i][j] == 1) {
        return 0;
    }
    
    int right = helperBF2(arr, n, m, i, j + 1); // call for right element.
    int down = helperBF2(arr, n, m, i + 1, j); // call for down element.
    int diagonal = helperBF2(arr, n, m, i + 1, j + 1); // call for diagonal element.
    
    int maxSize = 1 + min(right, min(down, diagonal));
    
    return maxSize;
}

int findMaxSquareWithAllZerosBF(int **arr, int n, int m) { // Brute Force Solution
    int maxSize = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                int size = helperBF1(arr, n, m, i, j);
                // int size = helperBF2(arr, n, m, i, j);
        
                if (size > maxSize) {
                    maxSize = size;
                }
            }
        }
    }
    return maxSize;
}

int helperMemo1(int **arr, int n, int m, int i, int j, vector<vector<int>> &ans) {
    // This is bottom to top approach, we are taken up, left and diagonal element as 
    // parameters to decide matrix size at ans[i][j].
    if (i < 0 || j < 0 || arr[i][j] == 1) {
        return 0;
    }

    if (ans[i][j] != -1) {
        return ans[i][j];
    }

    int diagonalElement = helperMemo1(arr, n, m, i-1, j-1, ans); // call for diagonal element.
    int prevRowElement = helperMemo1(arr, n, m, i-1, j, ans); // call for upward element.
    int prevColElement = helperMemo1(arr, n, m, i, j-1, ans); // call for left element.

    int result = 1 + min(diagonalElement, min(prevRowElement, prevColElement));
    // which one is minimum we can take that as the square and add one 0 it.
    ans[i][j] = result; // store the result for other calls.
    return result;
}

int helperMemo2(int **arr, int n, int m, int i, int j, vector<vector<int>> &ans) {
    // This is top to bottom approach, we are taken down, right and diagonal element as 
    // parameters to decide matrix size at ans[i][j].
    if (i >= n || j >= m || arr[i][j] == 1) {
        return 0;
    }

    if (ans[i][j] != -1) {
        return ans[i][j];
    }
    
    int right = helperMemo2(arr, n, m, i, j + 1, ans); // call for right element.
    int down = helperMemo2(arr, n, m, i + 1, j, ans); // call for down element.
    int diagonal = helperMemo2(arr, n, m, i + 1, j + 1, ans); // call for diagonal element.
    
    int maxSize = 1 + min(right, min(down, diagonal));

    ans[i][j] = maxSize;
    return maxSize;
}

int findMaxSquareWithAllZerosMemo(int **arr, int n, int m) { // MEMOIZATION APPROACH
    vector<vector<int>> ans(n, vector<int>(m, -1));
    int maxSize = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (arr[i][j] == 0) {
                int size = helperMemo1(arr, n, m, i, j, ans);
                // int size = helperMemo2(arr, n, m, i, j, ans);
                if (size > maxSize) {
                    maxSize = size;
                }
            }
        }
    }
    return maxSize;
}

// DP APPROACH corresponding to BF1 & Memo1.

int findMaxSquareWithAllZerosDP1(int **arr, int n, int m) {
	if (n==0 || m==0) { // edge case
		return 0;
	}

	vector<vector<int>> ans(n, vector<int>(m, 0));
	for (int i=0; i<m; i++) { // lets initialize first row of dp table.
		if (arr[0][i] == 0) {
			ans[0][i] = 1;
		}
	}

	for (int i=0; i<n; i++) { // lets initialize first column of dp table.
		if (arr[i][0] == 0) {
			ans[i][0] = 1;
		}
	}

	for (int i=1; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (arr[i][j] == 0) {
                int prevDiagonalElement = ans[i-1][j-1];
                int prevRowElement = ans[i-1][j];
                int prevColElement = ans[i][j-1];
				ans[i][j] = 1 + min(prevDiagonalElement, min(prevRowElement, prevColElement));
			}
			else {
				ans[i][j] = 0;
			}
		}
	}

	int max = INT_MIN;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (ans[i][j] > max) {
				max = ans[i][j];
			}
		}
	}

	return max;
}

// DP APPROACH corresponding to BF2 & Memo2.

int findMaxSquareWithAllZerosDP2(int **arr, int n, int m) {
	if (n==0 || m==0) { // edge case
		return 0;
	}

	vector<vector<int>> ans(n, vector<int>(m, 0));
	for (int i=0; i<m; i++) { // lets initialize last row of dp table.
		if (arr[n-1][i] == 0) {
			ans[n-1][i] = 1;
		}
	}

	for (int i=0; i<n; i++) { // lets initialize last column of dp table.
		if (arr[i][m-1] == 0) {
			ans[i][m-1] = 1;
		}
	}

	for (int i = n - 2; i >= 0; i--) {
		for (int j = m - 2; j >= 0; j--) {
			if (arr[i][j] == 0) {
                int nextDiagonalElement = ans[i+1][j+1]; // call for diagonal element
                int nextRowElement = ans[i+1][j]; //  call for down Element
                int nextColElement = ans[i][j+1]; // call for right element.
				ans[i][j] = 1 + min(nextDiagonalElement, min(nextRowElement, nextColElement));
			}
			else {
				ans[i][j] = 0;
			}
		}
	}

	int max = INT_MIN;
	
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (ans[i][j] > max) {
				max = ans[i][j];
			}
		}
	}

	return max;
}