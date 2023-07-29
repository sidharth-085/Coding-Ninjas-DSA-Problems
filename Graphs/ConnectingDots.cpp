#include <vector>
using namespace std;

// Check if a cell is safe to visit
bool isSafe(vector<vector<char>>& board, int row, int col, char needColor, int n, int m) {
    if (row >= 0 && row < n && col >= 0 && col < m && board[row][col] == needColor) {
        return true;
    }
    return false;
}

// Depth-first search function
bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, int prevX, int prevY, int n, int m, char needColor) {
    if (visited[row][col]) {
        return true;
    }

    visited[row][col] = true;

    int newX, newY;

    // Explore all four adjacent cells (up, down, left, right)
    
    // Up
    newX = row - 1;
    newY = col;
    if (isSafe(board, newX, newY, needColor, n, m) && !(newX == prevX && newY == prevY)) {
        if (dfs(board, visited, newX, newY, row, col, n, m, needColor)) {
            return true;
        }
    }

    // Down
    newX = row + 1;
    newY = col;
    if (isSafe(board, newX, newY, needColor, n, m) && !(newX == prevX && newY == prevY)) {
        if (dfs(board, visited, newX, newY, row, col, n, m, needColor)) {
            return true;
        }
    }

    // Left
    newX = row;
    newY = col - 1;
    if (isSafe(board, newX, newY, needColor, n, m) && !(newX == prevX && newY == prevY)) {
        if (dfs(board, visited, newX, newY, row, col, n, m, needColor)) {
            return true;
        }
    }

    // Right
    newX = row;
    newY = col + 1;
    if (isSafe(board, newX, newY, needColor, n, m) && !(newX == prevX && newY == prevY)) {
        if (dfs(board, visited, newX, newY, row, col, n, m, needColor)) {
            return true;
        }
    }

    visited[row][col] = false;

    return false;
}

// Function to check if the board has any cycles
bool hasCycle(vector<vector<char>>& board, int n, int m) {
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                // Call DFS for each unvisited cell
                bool ans = dfs(board, visited, i, j, -1, -1, n, m, board[i][j]);
                if (ans) {
                    return true;
                }
            }
        }
    }
    return false;
}
