#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, char target) {
    int n = board.size();
    int m = board[0].size();

    // Check if the cell is within the bounds of the matrix
    if (row < 0 || row >= n || col < 0 || col >= m) {
        return false;
    }

    // Check if the cell contains the target character
    if (board[row][col] != target) {
        return false;
    }

    return true;
}

bool dfs(vector<vector<char>>& board, int row, int col, string word, int index) {
    // If we have reached the end of the word, return true
    if (index == word.length()) {
        return true;
    }

    // Check if the current cell is valid and contains the next character of the word
    if (isValid(board, row, col, word[index])) {
        // Mark the cell as visited by changing its value
        char temp = board[row][col];
        board[row][col] = '#'; // we can use visited 2d array for checking is the character is visited or not.

        // Check all the neighboring cells
        if (dfs(board, row - 1, col, word, index + 1) ||
            dfs(board, row + 1, col, word, index + 1) ||
            dfs(board, row, col - 1, word, index + 1) ||
            dfs(board, row, col + 1, word, index + 1) ||
            dfs(board, row - 1, col - 1, word, index + 1) ||
            dfs(board, row - 1, col + 1, word, index + 1) ||
            dfs(board, row + 1, col - 1, word, index + 1) ||
            dfs(board, row + 1, col + 1, word, index + 1)) {
            return true;
        }

        // Revert the cell back to its original value
        board[row][col] = temp;
    }

    return false;
}

bool hasPath(vector<vector<char>>& board, int n, int m) {
    string word = "CODINGNINJA";
    int wordLength = word.length();

    // Iterate through each cell of the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Check if the current cell can be the starting point of the word
            if (board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }

    if (hasPath(board, n, m)) {
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}