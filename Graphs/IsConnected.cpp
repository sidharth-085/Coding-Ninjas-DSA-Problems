#include <iostream>
#include <queue>
using namespace std;

void isConnectedByDFS(int **edges, int n, bool *visited, int startVertex) {
    visited[startVertex] = true;

    for (int i=0; i<n; i++) {
        if (i == startVertex) {
            continue;
        }
        if (edges[startVertex][i] == 1) {
            if (visited[i] == true) {
                continue;
            }
            else {
                isConnectedByDFS(edges, n, visited, i);
            }
        }
    }
}

void isConnectedByBFS(int **edges, int n, bool *visited, int startVertex) {
    queue<int> input;
    input.push(startVertex);
    visited[startVertex] = true;

    while (!input.empty()) {
        int top = input.front();
        input.pop();

        for (int i=0; i<n; i++) {
            if (i == top) {
                continue;
            }
            if (edges[top][i] == 1 && !visited[i]) {
                input.push(i);
                visited[i] = true;
            }
        }
    }
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
    
    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    isConnectedByDFS(edges, n, visited, 0);
    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;

    isConnectedByBFS(edges, n, visited, 0);
    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            cout << "false" << endl;
            return 0;
        }
    }
    cout << "true" << endl;
}