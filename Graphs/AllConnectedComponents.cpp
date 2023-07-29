#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// Function to perform Depth First Search (DFS) to find all connected components
void allConnectedComponentsByDFS(int **edges, int n, bool *visited, int startVertex, vector<int> &ans) {
    ans.push_back(startVertex); // Add the current vertex to the connected component
    visited[startVertex] = true; // Mark the current vertex as visited

    // Explore all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (i == startVertex) {
            continue; // Skip if the vertex is the same as the start vertex
        }
        if (edges[startVertex][i] == 1 && !visited[i]) {
            // If there is an edge between the current vertex and the adjacent vertex,
            // and the adjacent vertex is not visited, recursively explore the component
            allConnectedComponentsByDFS(edges, n, visited, i, ans);
        }
    }
}

void allConnectedComponentsByBFS(int **edges, int n, bool *visited, int startVertex, vector<int> &ans) {
    queue<int> input;
    input.push(startVertex); // Add the start vertex to the queue
    visited[startVertex] = true;

    while (!input.empty()) {
        int top = input.front();
        input.pop();

        ans.push_back(top); // Add the current vertex to the result vector

        for (int i = 0; i < n; i++) {
            if (i == top) {
                continue;
            }
            if (edges[top][i] == 1 && !visited[i]) {
                input.push(i); // Add the adjacent unvisited vertex to the queue
                visited[i] = true; // Mark the adjacent vertex as visited
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e; // Read the number of vertices (n) and edges (e)

    // Create an adjacency matrix to represent the graph
    int **edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0; // Initialize all elements to 0 (no edges present initially)
        }
    }

    // Read the edges of the graph
    for (int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second; // Read the endpoints of an edge

        edges[first][second] = 1; // Mark the edge between first and second as present
        edges[second][first] = 1; // Mark the edge between second and first as present (assuming an undirected graph)
    }

    // Create a visited array to keep track of visited vertices
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false; // Initialize all vertices as not visited
    }

    vector<int> ans; // Vector to store the vertices of each connected component

    // Iterate through all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // If the current vertex is not visited, perform DFS to find the connected component
            allConnectedComponentsByDFS(edges, n, visited, i, ans);

            sort(ans.begin(), ans.end()); // Sort the vertices in ascending order

            // Print the vertices of the connected component
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << " ";
            }
            ans.clear(); // Clear the vector for the next connected component
            cout << endl;
        }
    }

    vector<int> ans; // Vector to store the vertices of each connected component

    // Iterate through all vertices
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            // If the current vertex is not visited, perform BFS to find the connected component
            allConnectedComponentsByBFS(edges, n, visited, i, ans);

            sort(ans.begin(), ans.end()); // Sort the vertices in ascending order

            // Print the vertices of the connected component
            for (int j = 0; j < ans.size(); j++) {
                cout << ans[j] << " ";
            }
            ans.clear(); // Clear the vector for the next connected component
            cout << endl;
        }
    }

    // Deallocate the dynamically allocated memory
    for (int i = 0; i < n; i++) {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;

    return 0;
}