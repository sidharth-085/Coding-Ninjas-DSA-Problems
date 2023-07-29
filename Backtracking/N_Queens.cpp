#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// APPROACH 1: THIS IS NOT MUCH OPIMIZED APPROACH. We can improve it by using hashmap 
// and do the attack conditions in O(1) time.

// Function to copy the current solution to the answer vector
void copySolution(vector<vector<int>> &board, vector<vector<int>> &ans) {
    vector<int> temp;
    for (int i=0; i<board.size(); i++) {
        for (int j=0; j<board[i].size(); j++) {
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

// Function to check if it is safe to place a queen at a given position
bool isSafe(int row, int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    int x = row;
    int y = col;

    // Case 1: Check if queen exists in the same row and we are assuming that every 
    // column has only one queen so, this test case take over in row checking.
    while (y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        y--;
    }

    x = row;
    y = col;

    // Case 2: Check if queen exists in the upward diagonal
    while (x >= 0 && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x--;
        y--;
    }

    x = row;
    y = col;

    // Case 3: Check if queen exists in the downward diagonal
    while (x < n && y >= 0) {
        if (board[x][y] == 1) {
            return false;
        }
        x++;
        y--;
    }

    // If it is safe to place a queen at the given position
    return true;
}

// Recursive function to solve the N-Queens problem
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n) {
    // Base case: All columns have been explored (valid solution)
    if (col == n) {
        copySolution(board, ans);
        return;
    }

    // Explore all possible rows for the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, ans, n)) {
            // Place the queen at the current position
            board[row][col] = 1;

            // Recursively solve for the next column
            solve(col+1, board, ans, n);

            // Backtrack and remove the queen from the current position
            board[row][col] = 0;
        }
    }
}

// Function to find all valid solutions to the N-Queens problem
vector<vector<int>> nQueens(int n) {
    // Create an empty chessboard
    vector<vector<int>> board(n, vector<int>(n, 0));

    // Vector to store all valid solutions
    vector<vector<int>> ans;

    // Start solving the N-Queens problem from the first column
    solve(0, board, ans, n);

    // Return the vector containing all valid solutions
    return ans;
}

// APPROACH 2: BY USING HASHMAP approach.

// Function to check if it's safe to place a queen at a given position
bool isSafe(int row, int col, vector<vector<int>> &board, vector<vector<int>> &ans,
    int n, unordered_map<int, bool> &leftCheck, unordered_map<int, bool> &upDiagonalCheck,
    unordered_map<int, bool> &downDiagonalCheck) {

    // Check if there is a queen in the same row or in the upward and downward diagonals
    if (leftCheck[row] == true || upDiagonalCheck[n - 1 + col - row] == true || downDiagonalCheck[row + col] == true) {
        return false;
    }
    return true;
}

// Recursive function to solve the N-Queens problem
void solve(int col, vector<vector<int>> &board, vector<vector<int>> &ans, int n,
    unordered_map<int, bool> &leftCheck, unordered_map<int, bool> &upDiagonalCheck,
    unordered_map<int, bool> &downDiagonalCheck) {

    // Base case: All columns are filled, so we found a valid configuration
    if (col == n) {
        copySolution(board, ans); // Copy the current board configuration to the solutions vector
        return;
    }

    // Try placing a queen in each row of the current column
    for (int row = 0; row < n; row++) {
        if (isSafe(row, col, board, ans, n, leftCheck, upDiagonalCheck, downDiagonalCheck)) {
            board[row][col] = 1; // Place the queen in the current position

            leftCheck[row] = true; // Mark the row as occupied by a queen
            upDiagonalCheck[n - 1 + col - row] = true; // Mark the upward diagonal as occupied
            downDiagonalCheck[row + col] = true; // Mark the downward diagonal as occupied

            // Recursively solve for the next column
            solve(col + 1, board, ans, n, leftCheck, upDiagonalCheck, downDiagonalCheck);

            // Backtrack: Remove the queen and mark the corresponding positions as available again
            board[row][col] = 0;

            leftCheck[row] = false;
            upDiagonalCheck[n - 1 + col - row] = false;
            downDiagonalCheck[row + col] = false;
        }
    }
}

// Function to find all solutions to the N-Queens problem
vector<vector<int>> nQueens(int n) {
    vector<vector<int>> board(n, vector<int>(n, 0)); // Initialize the chessboard
    vector<vector<int>> ans; // Vector to store all valid solutions

    unordered_map<int, bool> leftCheck; // Map to keep track of occupied rows
    unordered_map<int, bool> upDiagonalCheck; // Map to keep track of occupied upward diagonals
    unordered_map<int, bool> downDiagonalCheck; // Map to keep track of occupied downward diagonals

    solve(0, board, ans, n, leftCheck, upDiagonalCheck, downDiagonalCheck); // Solve the N-Queens problem

    return ans; // Return the solutions
}