#include <iostream>
#include <queue>
using namespace std;

// Depth-First Search (DFS) function
bool DFS(int **edges, int n, bool *visited, int startVertex, int target) {
    if (edges[startVertex][target] == 1) { // If there is a direct edge between startVertex and target, return true (base case)
        return true;
    }

    visited[startVertex] = true; // Mark the start vertex as visited
    for (int i = 0; i < n; i++) {
        if (i == startVertex) {
            continue;
        }
        if (edges[startVertex][i] == 1 && !visited[i]) { // If there is an edge between startVertex and i, and i is not visited
            bool ans = DFS(edges, n, visited, i, target); // Recursively call DFS on vertex i
            if (ans) {
                return true; // If a path is found from i to target, return true
            }
        }
    }
    return false; // If no path is found, return false
}

// Breadth-First Search (BFS) function
bool BFS(int **edges, int n, int startVertex, int target) {
    if (edges[startVertex][target] == 1) { // If there is a direct edge between startVertex and target, return true (base case)
        return true;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    queue<int> input;
    input.push(startVertex);
    visited[startVertex] = true;

    while (!input.empty()) {
        int top = input.front();
        input.pop();

        if (edges[top][target] == 1) { // If there is an edge between top and target, return true
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (i == top) {
                continue;
            }
            if (edges[top][i] == 1 && !visited[i]) { // If there is an edge between top and i, and i is not visited
                input.push(i);
                visited[i] = true; // Mark i as visited
            }
        }
    }
    delete [] visited;
    return false; // If no path is found, return false
}

void isPathPresent(int **edges, int n, int value1, int value2) {
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }

    // DFS approach
    if (DFS(edges, n, visited, value1, value2)) { // Check if there is a path from value1 to value2 using DFS
        cout << "true" << endl;
        return;
    }
    cout << "false" << endl;

    // BFS approach
    if (BFS(edges, n, value1, value2)) { // Check if there is a path from value1 to value2 using BFS
        cout << "true" << endl;
        return;
    }
    cout << "false" << endl;
    delete [] visited;
}

int main() {
    int n; // Total number of nodes present in the graph
    int e; // Number of edges or connections between nodes
    cin >> n >> e;

    int **edges = new int *[n]; // Storing the connections between two nodes in a 2D matrix
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;

        edges[first][second] = 1; // Mark the edge between first and second as present
        edges[second][first] = 1; // Mark the edge between second and first as present (assuming an undirected graph)
    }

    int value1, value2;
    cin >> value1 >> value2;

    isPathPresent(edges, n, value1, value2);
    
    for (int i=0; i<n; i++) {
        delete edges[i];
    }

    delete [] edges;
}