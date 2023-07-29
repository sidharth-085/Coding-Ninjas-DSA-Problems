#include <iostream>
using namespace std;

void printByDFS(int **edges, int n, bool *visited, int startVertex) {
    cout << startVertex << " ";
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
                printByDFS(edges, n, visited, i);
            }
        }
    }
}

int main() {
    int n; // total number of nodes present in graph.
    int e; // number of edges or connections between nodes.
    cout << "Enter the number of nodes & edges : ";
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

    printByDFS(edges, n, visited, 0); // DFS is like pre-order traversal of Trees.
}