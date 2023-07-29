#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int N = 10;

// Function to print the crossword grid
void printGrid(vector<vector<char>>& grid) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
}

// Function to check if a word can be placed horizontally at a given position
bool canPlaceHorizontally(vector<vector<char>>& grid, string word, int row, int col) {
    int len = word.length();
    if (col + len > N) {
        return false;  // Word exceeds the grid boundary
    }
    for (int j = 0; j < len; j++) {
        if (grid[row][col + j] != '-' && grid[row][col + j] != word[j]) {
            return false;  // Conflict with existing word
        }
    }
    return true;
}

// Function to check if a word can be placed vertically at a given position
bool canPlaceVertically(vector<vector<char>>& grid, string word, int row, int col) {
    int len = word.length();
    if (row + len > N) {
        return false;  // Word exceeds the grid boundary
    }
    for (int i = 0; i < len; i++) {
        if (grid[row + i][col] != '-' && grid[row + i][col] != word[i]) {
            return false;  // Conflict with existing word
        }
    }
    return true;
}

// Function to place a word horizontally at a given position
void placeHorizontally(vector<vector<char>>& grid, string word, int row, int col) {
    int len = word.length();
    for (int j = 0; j < len; j++) {
        grid[row][col + j] = word[j];
    }
}

// Function to place a word vertically at a given position
void placeVertically(vector<vector<char>>& grid, string word, int row, int col) {
    int len = word.length();
    for (int i = 0; i < len; i++) {
        grid[row + i][col] = word[i];
    }
}

// Recursive function to solve the crossword
bool solveCrossword(vector<vector<char>>& grid, vector<string>& wordList, int startIndex) {
    if (startIndex == wordList.size()) {
        return true;  // All words are placed successfully
    }
    string word = wordList[startIndex];
    int len = word.length();

    // Try placing the word horizontally at each position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (canPlaceHorizontally(grid, word, i, j)) {
                vector<vector<char>> prevGrid = grid;
                placeHorizontally(grid, word, i, j);
                if (solveCrossword(grid, wordList, startIndex + 1)) {
                    return true;
                }
                grid = prevGrid;  // Backtrack
            }
        }
    }

    // Try placing the word vertically at each position
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (canPlaceVertically(grid, word, i, j)) {
                vector<vector<char>> prevGrid = grid;
                placeVertically(grid, word, i, j);
                if (solveCrossword(grid, wordList, startIndex + 1)) {
                    return true;
                }
                grid = prevGrid;  // Backtrack
            }
        }
    }

    return false;
}

int main() {
    vector<vector<char>> grid(10, vector<char>(10, '+'));
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++) {
            cin >> grid[i][j];
        }
    }

    string words;
    cin >> words;

    vector<string> wordList;
    string temp = "";

    // spliting the words and insert them into string vector.

    for (int i=0; i<words.size(); i++) {
        if (words[i] == ';') {
            wordList.push_back(temp);
            temp = "";
        }
        else {
            temp = temp + words[i];
        }        
    }
    wordList.push_back(temp);

    solveCrossword(grid, wordList, 0);

    printGrid(grid);   
}