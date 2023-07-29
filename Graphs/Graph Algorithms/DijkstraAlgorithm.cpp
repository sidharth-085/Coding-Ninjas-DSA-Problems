#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Function to find the vertex with the minimum weight among the unvisited vertices
int minWeightVertex(int *weights, int n, bool* nonVisited) {
    int minVertex;
    int minWeight = INT_MAX;
    for (int i = 0; i < n; i++) {
        int currentWeight = weights[i];
        if (minWeight > currentWeight && nonVisited[i] == true) {
            minVertex = i;
            minWeight = currentWeight;
        }
    }
    return minVertex;
}

void dijkstraAlgorithm(int** edges, int n, int e) {
    int *weights = new int[n];
    bool *nonVisited = new bool[n];
    
    for (int i=0; i<n; i++) {
        weights[i] = INT_MAX;
        nonVisited[i] = true;
    }

    weights[0] = 0;

    int count = n;

    // Selecting minimum weight edges and updating the information array
    while (count > 0) {
        int minVertex = minWeightVertex(weights, n, nonVisited);
        nonVisited[minVertex] = false;
        count--;

        // Updating the weights and parents of the adjacent vertices
        for (int i = 0; i < n; i++) {
            if (i == minVertex) {
                continue;
            }

            int currPathWeight = weights[minVertex] + edges[minVertex][i];
            if (edges[minVertex][i] != 0 && nonVisited[i] && weights[i] > currPathWeight) {
                weights[i] = currPathWeight;
            }
        }
    }

    // Printing the minimum spanning tree edges
    for (int i = 0; i < n; i++) {
        cout << i << " " << weights[i] << endl;
    }

    // Dealocate the parent and weights array

    delete [] weights;
    delete [] nonVisited;
}

int main() {
    int n, e;
    cin >> n >> e;

    int** edges = new int*[n];
    for (int i = 0; i < n; i++) {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++) {
            edges[i][j] = 0;
        }
    }

    // Reading the graph edges and weights
    for (int i = 0; i < e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;

        edges[source][destination] = weight;
        edges[destination][source] = weight;
    }

    dijkstraAlgorithm(edges, n, e); 

    return 0;
}