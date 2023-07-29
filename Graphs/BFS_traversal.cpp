#include <iostream>
#include <queue>
using namespace std;

void printByBFS(int **edges, int n, bool *visited, int startVertex) {
    queue<int> input;
    input.push(startVertex);
    visited[startVertex] = true;

    while (!input.empty()) {
        int top = input.front();
        input.pop();

        cout << top << " ";

        for (int i=0; i<n; i++) {
            if (i == top) {
                continue;
            }
            if (edges[top][i] == 1 && visited[i] == false) {
                input.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    int n; // total number of nodes present in graph.
    int e; // number of edges or connections between nodes.
    cin >> n >> e;

    int **edges = new int*[n]; // storing the connections between two nodes in 2D matrix.
    for (int i=0; i<n; i++) {
        edges[i] = new int[n];
        for (int j=0; j<n; j++) {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;

        edges[first][second] = 1;
        edges[second][first] = 1;
    }

    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    int startVertex = 0;

    printByBFS(edges, n, visited, 0); // BFS is similar to LevelWise of Trees.
}