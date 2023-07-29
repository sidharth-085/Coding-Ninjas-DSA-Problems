#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isSafe(int newX, int newY, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited) {
    if (newX >=0 && newX < n && newY >=0 && newY < n && arr[newX][newY] == 1 && visited[newX][newY] == false) {
        return true;
    }
    return false;
}

void solveWithForLoop(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, vector<string> &ans, string path) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    string str = "DLRU";
    int incrementX[4] = {1, 0, 0, -1};
    int incrementY[4] = {0, 1, -1, 0};

    for (int i=0; i<4; i++) {
        int newX = x + incrementX[i];
        int newY = y + incrementY[i];

        if (isSafe(newX, newY, arr, n, visited)) {
            visited[x][y] = true;
            solveWithForLoop(newX, newY, arr, n, visited, ans, path + str[i]);
            visited[x][y] = false;
        }
    }
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<vector<bool>> &visited, vector<string> &ans, string path) {
    if (x == n-1 && y == n-1) {
        ans.push_back(path);
        return;
    }

    visited[x][y] = true;

    // down
    if (isSafe(x+1, y, arr, n, visited)) {
        solve(x+1, y, arr, n, visited, ans, path + 'D');
    }

    // left
    if (isSafe(x, y-1, arr, n, visited)) {
        solve(x, y-1, arr, n, visited, ans, path + 'L');
    }

    // right
    if (isSafe(x, y+1, arr, n, visited)) {
        solve(x, y+1, arr, n, visited, ans, path + 'R');
    }

    // up
    if (isSafe(x-1, y, arr, n, visited)) {
        solve(x-1, y, arr, n, visited, ans, path + 'U');
    }

    visited[x][y] = false;
}

vector<string> searchMaze(vector<vector<int>> &arr, int n) {
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    string path = "";
    vector<string> ans;
    solve(0, 0, arr, n, visited, ans, path);
    // solveWithForLoop(0, 0, arr, n, visited, ans, path);
    return ans;
}

// TYPE 2: INSTEAD OF STRING, IT SHOULD PRINT THE PATH IN TERMS OF NUMBERS

// APPROACH 1: 

bool isSafe(int row, int col,  vector<vector<int>> &arr, vector<vector<int>> &path, int n) {
    // Check if the given position is within the grid bounds
    // and the cell is valid (1) and not visited before (0)
	if (row >= 0 && row < n && col >= 0 && col < n && arr[row][col] == 1 && path[row][col] == 0) {
		return true;				
	}
	return false;
}

void solve(int row, int col, vector<vector<int>> &arr, vector<vector<int>> &path, int n) {
    // If the current position is the destination (bottom-right cell),
    // mark it as part of the path, print the path, and backtrack.
	if (row == n-1 && col == n-1) {
		path[row][col] = 1;
		
		// Print the path
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) {
				cout << path[i][j] << " ";
			}
			cout << endl;
		}
		
		path[row][col] = 0; // Backtrack by marking the current cell as not part of the path
		return;
	}

	path[row][col] = 1; // Mark the current cell as part of the path

    // Explore the neighboring cells in a specific order: down, left, right, up.

    // Check if it's safe to move down
	if (isSafe(row+1, col, arr, path, n)) {
		solve(row+1, col, arr, path, n); // Recursively solve the subproblem by moving down
	}

    // Check if it's safe to move left
	if (isSafe(row, col-1, arr, path, n)) {
		solve(row, col-1, arr, path, n); // Recursively solve the subproblem by moving left
	}

    // Check if it's safe to move right
	if (isSafe(row, col+1, arr, path, n)) {
		solve(row, col+1, arr, path, n); // Recursively solve the subproblem by moving right
	}

    // Check if it's safe to move up
	if (isSafe(row-1, col, arr, path, n)) {
		solve(row-1, col, arr, path, n); // Recursively solve the subproblem by moving up
	}

	path[row][col] = 0; // Backtrack by marking the current cell as not part of the path
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(n, 0));

	// Input the grid values
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}

	vector<vector<int>> path(n, vector<int>(n, 0)); // Initialize the path grid

	solve(0, 0, arr, path, n); // Start solving the problem from the top-left corner

	return 0;
}

// APPROACH 2: 

// Function to print the solution matrix
void printsolution(int solution[20][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
    }
}

// Recursive function to solve the maze
void solveMaze(int maze[20][20], int solution[20][20], int row, int col, int n) {
    // Base case: reached the destination
    if (row == n - 1 && col == n - 1) {
        solution[row][col] = 1;
        printsolution(solution, n);
        cout << endl;
        return;
    }

    // Check if the current cell is valid or out of bounds
    if (row > n - 1 || row < 0 || col > n - 1 || col < 0) {
        return;
    }

    // Check if the current cell is blocked or already visited
    if (maze[row][col] == 0 || solution[row][col] == 1) {
        return;
    }

    // Mark the current cell as part of the solution path
    solution[row][col] = 1;

    // Recursively explore all possible directions: up, down, left, right
    solveMaze(maze, solution, row - 1, col, n); // up
    solveMaze(maze, solution, row + 1, col, n); // down
    solveMaze(maze, solution, row, col - 1, n); // left
    solveMaze(maze, solution, row, col + 1, n); // right

    // Backtrack: unmark the current cell as part of the solution path
    solution[row][col] = 0;
}

// Function to solve the maze
void ratInAMaze(int maze[20][20], int n) {
    int solution[20][20];

    // Initialize the solution matrix with all 0s
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            solution[i][j] = 0;
        }
    }

    // Start solving the maze from the top-left corner
    solveMaze(maze, solution, 0, 0, n);
}

int main() {
    int n;
    cin >> n;

    int maze[20][20];

    // Input the maze matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> maze[i][j];
        }
    }

    // Solve the maze
    ratInAMaze(maze, n);

    return 0;
}