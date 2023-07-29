#include <iostream>
#include <queue>
#include <climits>
using namespace std;

// Approach 1: Using linear search to find the minimum weight vertex

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

void primAlgorithm(int** edges, int n, int e) {
    int *parent = new int[n];
    int *weights = new int[n];
    bool* nonVisited = new bool[n];
    
    for (int i=0; i<n; i++) {
        weights[i] = INT_MAX;
        nonVisited[i] = true;
    }

    parent[0] = -1;
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
            if (edges[minVertex][i] != 0 && nonVisited[i] == true && weights[i] > edges[minVertex][i]) {
                weights[i] = edges[minVertex][i];
                parent[i] = minVertex;
            }
        }
    }

    // Printing the minimum spanning tree edges
    for (int i = 1; i < n; i++) {
        cout << min(i, parent[i]) << " " << max(i, parent[i]) << " " << weights[i] << endl;
    }

    // Dealocate the parent and weights array

    delete [] parent;
    delete [] weights;
    delete [] nonVisited;
}

// Approach 2: Using a priority queue (min heap) to find the minimum weight edge

class edge {
public:
    int vertex;
    int parent;
    int weight;

    void printEdge() {
        cout << min(vertex, parent) << " " << max(vertex, parent) << " " << weight << endl;
    }
};

// Comparison function for edges based on their weights
class CompareEdges {
    public:
    bool operator()(const edge& e1, const edge& e2) {
        return e1.weight > e2.weight;
    }
};

void primsAlgorithm(int** edges, int n, int e) {
    edge* info = new edge[n]; 
    bool* nonVisited = new bool[n];

    for (int i = 0; i < n; i++) {
        info[i].vertex = i;
        nonVisited[i] = true;

        if (i == 0) {
            info[i].parent = -1;
            info[i].weight = 0;
        }
        else {
            info[i].weight = INT_MAX;
        }
    }

    int count = n;

    priority_queue<edge, vector<edge>, CompareEdges> pq;
    pq.push(info[0]);

    // Selecting minimum weight edges using a priority queue and updating the information array
    while (count > 0 && !pq.empty()) {
        edge minEdge = pq.top();
        pq.pop();

        nonVisited[minEdge.vertex] = false;
        count--;

        // Updating the weights and parents of the adjacent vertices
        for (int i = 0; i < n; i++) {
            if (i == minEdge.vertex)
                continue;

            if (edges[minEdge.vertex][i] != 0 && nonVisited[i] && info[i].weight > edges[minEdge.vertex][i]) {
                info[i].weight = edges[minEdge.vertex][i];
                info[i].parent = minEdge.vertex;
                pq.push(info[i]);
            }
        }
    }

    // Printing the minimum spanning tree edges
    for (int i = 1; i < n; i++) {
        info[i].printEdge();
    }
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

    primAlgorithm(edges, n, e); // Using Approach 1
    primsAlgorithm(edges, n, e); // Using Approach 2

    return 0;
}