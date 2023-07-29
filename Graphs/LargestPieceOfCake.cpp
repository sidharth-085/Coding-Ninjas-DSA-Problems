#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Function to check if a cell is safe to visit
bool isSafe(vector<vector<int>> &cake, int size, int row, int col) {
    // Check if row and column are within bounds and the cell contains 1
    if (row >= 0 && row < size && col >= 0 && col < size && cake[row][col] == 1) {
        return true;
    }
    return false;
}

// Depth-first search (DFS) function to explore the cake
int dfs(vector<vector<int>> &cake, int size, int row, int col, vector<vector<bool>> &visited) {
    // If we have reached the end of the cake, return 1
    if (row == size || col == size) {
        return 1;
    }
    
    int smallAns = 1;
    visited[row][col] = true;

    // Explore the neighboring cells

    // Move to the cell above
    int newRow = row - 1;
    int newCol = col;

    // Check if the cell is safe to visit and hasn't been visited before
    if (isSafe(cake, size, newRow, newCol) && visited[newRow][newCol] == false) {
        // Add the result of the DFS from the new cell to the current answer
        smallAns = smallAns + dfs(cake, size, newRow, newCol, visited);
    }

    // Move to the cell below
    newRow = row + 1;
    newCol = col;

    if (isSafe(cake, size, newRow, newCol) && visited[newRow][newCol] == false) {
        smallAns = smallAns + dfs(cake, size, newRow, newCol, visited);
    }

    // Move to the cell on the left
    newRow = row;
    newCol = col - 1;

    if (isSafe(cake, size, newRow, newCol) && visited[newRow][newCol] == false) {
        smallAns = smallAns + dfs(cake, size, newRow, newCol, visited);
    }

    // Move to the cell on the right
    newRow = row;
    newCol = col + 1;

    if (isSafe(cake, size, newRow, newCol) && visited[newRow][newCol] == false) {
        smallAns = smallAns + dfs(cake, size, newRow, newCol, visited);
    }

    // Return the final answer for the current cell
    return smallAns;
}

// Function to get the size of the biggest piece of cake
int getBiggestPieceSize(vector<vector<int>> &cake, int size) {
    vector<vector<bool>> visited(size, vector<bool>(size, false));
    int max = INT_MIN;

    // Iterate through each cell in the cake
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            // If the cell is not visited and contains 1, perform DFS from that cell
            if (visited[i][j] == false && cake[i][j] == 1) {
                int ans = dfs(cake, size, i, j, visited);
                // Update the maximum size if the current piece is larger
                if (ans > max) {
                    max = ans;
                }
            }
        }
    }
    // Return the size of the biggest piece
    return max;
}