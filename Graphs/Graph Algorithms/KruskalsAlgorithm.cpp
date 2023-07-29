#include <iostream>
#include <algorithm>
using namespace std;

// Minimum spanning tree is the tree which has all vertices of the graph and having the
// minimum possible path i.e. what makes an graph a tree when graph of n nodes has minimum
// n-1 edges, it is tree. And making an MST from graph tells the shortest path in a
// weighted, undirected and connected graph. 

int find(int vertex, vector<int> &parent) { // function for union-find algorithm.
    int current = vertex;
    while (parent[current] != current) {
        current = parent[current];
    }
    return current;
}

void kruskalsAlgo(int **edges, int n, vector<vector<bool>> &visited) {
    vector<vector<int>> ans(n, vector<int>(n, 0));  // Store the MST edges and their weights

    int count = 0;  // Count of edges added to the MST

    vector<int> parent(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;  // Initialize each vertex as its own parent
    }

    while (count != n - 1) {
        int minEdgeWeight = INT_MAX;
        int minEdgeRow = -1;
        int minEdgeCol = -1;

        // Find the minimum weight edge that has not been visited yet
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (edges[i][j] != 0 && minEdgeWeight > edges[i][j] && visited[i][j] == false) {
                    minEdgeRow = i;
                    minEdgeCol = j;
                    minEdgeWeight = edges[i][j];
                }
            }
        }

        visited[minEdgeRow][minEdgeCol] = true;  // Mark the edge as visited

        int parent1 = find(minEdgeRow, parent);  // Find the parent of the source vertex
        int parent2 = find(minEdgeCol, parent);  // Find the parent of the destination vertex

        if (parent1 != parent2) {
            count++;
            ans[minEdgeRow][minEdgeCol] = minEdgeWeight;  // Add the edge to the MST
        }
        parent[parent1] = parent2;  // Union operation: Update the parent of source vertex
    }

    // Print the MST edges
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j] != 0) {
                cout << i << " " << j << " " << ans[i][j] << endl;
            }
        }
    }
}

// Approach 2

class edge {
    public:
    int source;
    int destination;
    int weight;

    void printEdge() {
        cout << min(source, destination) << " " << max(source, destination) << " " << weight << endl;
    }
};

int find(int vertex, int *parent) { // function for union-find algorithm.
    int current = vertex;
    while (parent[current] != current) {
        current = parent[current];
    }
    return current;
}

bool compare(edge e1, edge e2) {
    return e1.weight < e2.weight;
}

void unionFindKruskalsAlgo(edge *edges, int v, int e) {
    sort(edges, edges+e, compare);

    int count = 0;
    int i = 0;

    edge *output = new edge[v-1];

    int *parent = new int[v];
    for (int i=0; i<v; i++) {
        parent[i] = i;
    }

    while (count != v-1) {
        edge currentEdge = edges[i];

        int parent1 = find(currentEdge.source, parent);
        int parent2 = find(currentEdge.destination, parent);

        if (parent1 != parent2) {
            count++;
            output[count] = currentEdge;
        } 
        parent[parent1] = parent2;
        i++;
    }

    for (int i=0; i<v-1; i++) {
        edges[i].printEdge();
    }
}

int main() {

    // Approach 1

    int v, e;
    cin >> v >> e;

    int **edges = new int*[v];
    for (int i = 0; i < v; i++) {
        edges[i] = new int[v];
        for (int j = 0; j < v; j++) {
            edges[i][j] = 0;  // Initialize the edges matrix with zeros
        }
    }

    for (int i = 0; i < e; i++) {
        int first, second, weight;
        cin >> first >> second >> weight;

        edges[first][second] = weight;  // Assign the weight to the corresponding edge
        edges[second][first] = weight;  // Since the graph is undirected, update the symmetric edge as well
    }

    vector<vector<bool>> visited(v, vector<bool>(v, false));  // Initialize the visited matrix with false

    kruskalsAlgo(edges, v, visited);

    // Deallocate memory
    for (int i = 0; i < v; i++) {
        delete[] edges[i];
    }
    delete[] edges;

    // Approach 2

    int v, e;
    cin >> v >> e;

    edge *Edges = new edge[e];
    for (int i=0; i<e; i++) {
        int source, destination, weight;
        cin >> source >> destination >> weight;

        Edges[i].source = source;
        Edges[i].destination = destination;
        Edges[i].weight = weight;
    }

    unionFindKruskalsAlgo(Edges, v, e);
}