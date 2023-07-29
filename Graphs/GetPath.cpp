#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Function to find the path using Breadth-First Search (BFS)
vector<int> getPathByBFS(int **edges, int n, int startVertex, int target) {
    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    vector<int> ans; // Stores the path from startVertex to target
    vector<int> parent(n, -1); // Stores the parent of each vertex in the path
    queue<int> input;

    input.push(startVertex);
    visited[startVertex] = true;
    parent[startVertex] = -1;

    while (!input.empty()) {
        int top = input.front();
        input.pop();

        if (top == target) {
            // If the target vertex is reached, backtrack and store the path
            int current = top;
            while (current != -1) {
                ans.push_back(current);
                current = parent[current]; 
            }
            return ans;
        }

        // Explore the neighboring vertices
        for (int i=0; i<n; i++) {
            if (i == top) {
                continue;
            }
            if (edges[top][i] == 1) {
                if (visited[i] == true) {
                    continue;
                }
                else {
                    input.push(i);
                    visited[i] = true;
                    parent[i] = top;
                }
            }
        }
    }
    return ans;
}

// Function to find the path using Depth-First Search (DFS)
vector<int> getPathByDFS(int **edges, int n, bool *visited, int startVertex, int target) {
    vector<int> ans; // Stores the path from startVertex to target
    if (startVertex == target) {
        ans.push_back(target);
        return ans;
    }

    visited[startVertex] = true;

    // Explore the neighboring vertices
    for (int i=0; i<n; i++) {
        if (i == startVertex) {
            continue;
        }
        if (edges[startVertex][i] == 1) {
            if (visited[i] == true) {
                continue;
            }
            else {
                // Recursively find the path from the neighboring vertex to the target
                vector<int> temp = getPathByDFS(edges, n, visited, i, target);
                if (!temp.empty()) {
                    temp.push_back(startVertex);
                    return temp;
                }
            }
        }
    }

    return ans;
} 

int main() {
    int n, e;
    cin >> n >> e;

    int **edges = new int*[n];
    for (int i=0; i<n; i++) {
        edges[i] = new int[n];
        for (int j=0; j<n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) { // input for graph
        int first, second;
        cin >> first >> second;

        edges[first][second] = 1; // Mark the edge between first and second as present
        edges[second][first] = 1; // Mark the edge between second and first as present (assuming an undirected graph)
    }

    int start, end;
    cin >> start >> end;

    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    vector<int> ansByDFS = getPathByDFS(edges, n, visited, start, end);
    vector<int> ansByBFS = getPathByBFS(edges, n, start, end);
    
    // Print the path found by DFS
    if (!ansByDFS.empty()) {
        for (int i=0; i < ansByDFS.size(); i++) {
            cout << ansByDFS[i] << " ";
        }
    }

    // Print the path found by BFS
    if (!ansByBFS.empty()) {
        for (int i=0; i < ansByBFS.size(); i++) {
            cout << ansByBFS[i] << " ";
        }
    }
}