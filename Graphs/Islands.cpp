#include <iostream>
#include <vector>
#include <queue>
using namespace std;



void islandsByDFS(int **edges, int n, bool *visited, int startVertex) {
    visited[startVertex] = true; // Mark the current vertex as visited

    // Explore all adjacent vertices
    for (int i = 0; i < n; i++) {
        if (i == startVertex) {
            continue; // Skip if the vertex is the same as the start vertex
        }
        if (edges[startVertex][i] == 1 && !visited[i]) {
            // If there is an edge between the current vertex and the adjacent vertex,
            // and the adjacent vertex is not visited, recursively explore the component
            islandsByDFS(edges, n, visited, i);
        }
    }
}

void islandsByBFS(int **edges, int n, bool *visited, int startVertex) {
    queue<int> input;
    input.push(startVertex); // Add the start vertex to the queue
    visited[startVertex] = true;

    while (!input.empty()) {
        int top = input.front();
        input.pop();

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

    int count = 0; // the count maintains number of islands.

    // Iterate through all vertices
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            // If the current vertex is not visited, perform DFS to find the connected component
            islandsByDFS(edges, n, visited, i);
            count++; // when any vertex is not visited after DFS traversal, increase count by 1.
        }
    }
    cout << count << endl;

    // Iterate through all vertices
    for (int i = 0; i < n; i++) {
        if (visited[i] == false) {
            // If the current vertex is not visited, perform BFS to find the connected component
            islandsByBFS(edges, n, visited, i);
            count++; // when any vertex is not visited after BFS traversal, increase count by 1.
        }
    }
    cout << count << endl;
}