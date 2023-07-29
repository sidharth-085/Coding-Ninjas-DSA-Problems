#include <iostream>
#include <queue>
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

void DFS(int **edges, int n) {
    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            printByDFS(edges, n, visited, i); // start from that vertex which is not visited yet.
        }
    }
    delete [] visited;
}

void BFS(int **edges, int n) {
    bool *visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }

    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            printByBFS(edges, n, visited, i); // start from that vertex which is not visited yet.
        }
    }
    delete [] visited;
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

    int startVertex = 0;

    cout << "BFS Traversal" << endl;
    BFS(edges, n); // BFS is similar to LevelWise traversal of Trees.
    cout << endl;

    cout << "DFS Traversal" << endl;
    DFS(edges, n); // DFS is similar to Pre-order traversal of Trees.
    cout << endl;

    for (int i=0; i<n; i++) {
        delete edges[i];
    }
    delete [] edges;
}