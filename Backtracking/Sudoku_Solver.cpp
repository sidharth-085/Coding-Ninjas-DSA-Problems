#include <iostream>
using namespace std;

// METHOD 1: BOARD AS 2D VECTOR

bool isSafe(int row, int col, vector<vector<int>> &board, int val) {
    for (int i = 0; i < 9; i++) {
        // Check for same value in the same row
        if (board[row][i] == val) {
            return false;
        }
        // Check for same value in the same column
        if (board[i][col] == val) {
            return false;
        }
        // Check for same value in the 3x3 matrix
        if (board[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
            return false;
        }
    }
    return true; // Safe to place the value
}

bool solve(vector<vector<int>> &board) {
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (board[row][col] == 0) { // Find an empty cell
                for (int val = 1; val <= 9; val++) { // Try each value from 1 to 9
                    if (isSafe(row, col, board, val)) { // Check if the value is safe to place
                        board[row][col] = val; // Place the value

                        bool isSolutionPossible = solve(board); // Recursively solve the Sudoku
                        if (isSolutionPossible) {
                            return true; // If a solution is found, return true
                        } else {
                            board[row][col] = 0; // If a solution is not found, backtrack by resetting the cell
                        }
                    }
                }
                return false; // If no value is safe to place, backtrack
            }                                                        
        }
    }
    return true; // If all cells are filled, the Sudoku is solved
}

void solveSudoku(vector<vector<int>>& sudoku) {
    solve(sudoku); // Solve the Sudoku puzzle
}

// METHOD 2: BOARD AS 1D VECTOR (2D BOARD INTO 1D BOARD) 

const int BOARD_SIZE = 9;

bool isSafe(const vector<int>& board, int row, int col, int val) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check for same row
        if (board[row * BOARD_SIZE + i] == val) {
            return false;
        }
        // Check for same column
        if (board[i * BOARD_SIZE + col] == val) {
            return false;
        }
    }

    // Check for particular subgrid (3x3)
    int subgridStartRow = 3 * (row / 3);
    int subgridStartCol = 3 * (col / 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int r = subgridStartRow + i;
            int c = subgridStartCol + j;
            if (board[r * BOARD_SIZE + c] == val) {
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<int>& board, int index) {
    if (index == BOARD_SIZE * BOARD_SIZE) {
        return true;  // All cells filled
    }

    int row = index / BOARD_SIZE;
    int col = index % BOARD_SIZE;

    if (board[index] != 0) {
        return solve(board, index + 1);  // Skip already filled cell
    }

    for (int val = 1; val <= BOARD_SIZE; val++) {
        if (isSafe(board, row, col, val)) {
            board[index] = val;

            bool isSolutionPossible = solve(board, index + 1);
            if (isSolutionPossible) {
                return true;
            }
            else {
                board[index] = 0;  // Reset cell if no solution found
            }
        }
    }
    return false;
}

void solveSudoku(vector<vector<int>>& sudoku) {
    vector<int> board(BOARD_SIZE * BOARD_SIZE, 0);
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i * BOARD_SIZE + j] = sudoku[i][j];
        }
    }

    if (solve(board, 0)) {
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                sudoku[i][j] = board[i * BOARD_SIZE + j];
            }
        }
    }
}

// METHOD 3: It only checks is Sudoku solvable or not.

// Function to check if it is safe to place a value in a given position
bool check(int board[][9], int row, int col, int val)
{
    // Check if the value already exists in the current row or column
    for (int k = 0; k < 9; k++) {
        if (board[row][k] == val || board[k][col] == val) {
            return false;
        }
    }

    // Determine the top-left indices of the current 3x3 sub-grid
    int topRowIdx = row - (row % 3);
    int topColIdx = col - (col % 3);

    // Check if the value already exists in the current sub-grid
    for (int r = topRowIdx; r < topRowIdx + 3; r++) {
        for (int c = topColIdx; c < topColIdx + 3; c++) {
            if (board[r][c] == val) {
                return false;
            }
        }
    }

    return true; // Value can be placed in the current position
}

// Recursive helper function to solve the Sudoku puzzle
bool helper(int board[][9], int row, int col) {
    // Base case: All rows have been filled
    if (row == 9) {
        return true; // Sudoku puzzle is solved
    }

    // Move to the next column if the current column is filled
    if (col == 9) {
        return helper(board, row + 1, 0); // Move to the next row
    }

    // Skip the current position if it is already filled with a number
    if (board[row][col] != 0) {
        return helper(board, row, col + 1);
    }

    // Try placing values from 1 to 9 in the current position
    for (int k = 1; k <= 9; k++) {
        if (check(board, row, col, k)) {
            board[row][col] = k; // Place the value in the current position

            // Move to the next column and continue solving
            if (helper(board, row, col + 1)) {
                return true;
            }
            else {
                board[row][col] = 0; // Backtrack: Remove the value from the current position
            }
        }
    }

    return false; // No valid value can be placed in the current position
}

// Function to solve the Sudoku puzzle
bool sudokuSolver(int board[][9]) {
    return helper(board, 0, 0);
}

int main() {
    int board[9][9];

    // Input the Sudoku puzzle
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }

    // Solve the Sudoku puzzle and print the result
    if (sudokuSolver(board)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}