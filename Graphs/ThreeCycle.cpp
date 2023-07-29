#include <iostream>
using namespace std;

int checkForThreeCycle(int **edges, int n) {
    int count = 0;
    for (int i=0; i<n; i++) {    // Iterate over each node i
        for (int j=0; j<n; j++) {    // Iterate over each node j
            if (j == i) {
                continue;    // Skip if the nodes are the same
            }
            if (edges[i][j] == 1) {    // If there is an edge between nodes i and j
                for (int k=0; k<n; k++) {    // Iterate over each node k
                    if (k == i || k == j) {
                        continue;    // Skip if the nodes are the same as i or j
                    }
                    if (edges[j][k] == 1) {    // If there is an edge between nodes j and k
                        if (edges[i][k] == 1) {    // If there is an edge between nodes i and k
                            count++;    // Increment the count as we found a three-cycle
                        }
                    }
                }
            }
        }
    }

    int ans = count / 6;    // Divide the count by 6 because each three-cycle is counted 6 times
    return ans;    // Return the number of three-cycles found
}

int main() {
    int n; // total number of nodes present in graph.
    int e; // number of edges or connections between nodes.
    cin >> n >> e;

    int **edges = new int*[n]; // storing the connections between two nodes in 2D matrix.
    for (int i=0; i<n; i++) {
        edges[i] = new int[n];
        for (int j=0; j<n; j++) {
            edges[i][j] = 0;    // Initialize all edges to 0 (no connection)
        }
    }

    for (int i = 0; i < e; i++) {
        int first, second;
        cin >> first >> second;

        edges[first][second] = 1;    // Set edge between first and second nodes to 1
        edges[second][first] = 1;    // Set edge between second and first nodes to 1 (assuming an undirected graph)
    }

    cout << checkForThreeCycle(edges, n) << endl;    // Call the function to check for three-cycles and print the result
}