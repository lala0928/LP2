#include <iostream>       // For input/output operations
#include <vector>         // To use dynamic arrays (vectors)
#include <climits>        // For INT_MAX
using namespace std;

// Function to find the vertex with the minimum key value
// that is not yet included in the MST
int minKey(const vector<int>& key, const vector<bool>& mstSet, int V) {
    int min = INT_MAX;     // Initialize min value to infinity
    int min_index = -1;    // Index of the vertex with minimum key

    // Loop through all vertices to find the minimum key value
    for (int v = 0; v < V; v++) {
        // Check if the vertex is not in MST and has a smaller key
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }

    return min_index; // Return index of minimum key vertex
}

// Function to print the constructed MST using parent[] array
void printMST(const vector<int>& parent, const vector<vector<int>>& graph, int V) {
    cout << "Edge \tWeight\n"; // Print header
    // Loop from 1 to V-1 because 0 is the root node and has no parent
    for (int i = 1; i < V; i++) {
        // Print the edge between parent and current node, and its weight
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

// Function to construct and print MST for a given graph using Prim's algorithm
void primMST(const vector<vector<int>>& graph, int V) {
    vector<int> parent(V);       // Array to store the constructed MST
    vector<int> key(V, INT_MAX); // Key values to pick minimum weight edge (initialized to infinity)
    vector<bool> mstSet(V, false); // To keep track of vertices included in MST

    key[0] = 0;         // Start from the first vertex (0), so its key is 0
    parent[0] = -1;     // The root node of MST has no parent

    // The MST will have V vertices, so we loop V-1 times
    for (int count = 0; count < V - 1; count++) {
        // Pick the vertex u with the minimum key value that is not yet in MST
        int u = minKey(key, mstSet, V);

        mstSet[u] = true; // Include vertex u in MST

        // Update key and parent index of all adjacent vertices of u
        for (int v = 0; v < V; v++) {
            // Conditions:
            // 1. There is an edge from u to v (graph[u][v] != 0)
            // 2. v is not in MST yet
            // 3. The edge weight is less than the current key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;         // Update parent of v to u
                key[v] = graph[u][v];  // Update key to new minimum weight
            }
        }
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

// Main function: entry point of the program
int main() {
    int V; // Number of vertices

    cout << "Enter the number of vertices: ";
    cin >> V; // User inputs number of vertices

    // Create a 2D vector (adjacency matrix) and initialize with 0s
    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (" << V << " x " << V << "):\n";

    // User input for the adjacency matrix
    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j]; // Input weight for edge i-j

    // Call Prim’s algorithm to find MST
    cout << "\nMinimum Spanning Tree using Prim's Algorithm:\n";
    primMST(graph, V);

    return 0; // Program ends
}

// Enter the number of vertices: 5
// Enter the adjacency matrix (5 x 5):
// 0 2 0 6 0
// 2 0 3 8 5
// 0 3 0 0 7
// 6 8 0 0 9
// 0 5 7 9 0

// Minimum Spanning Tree using Prim's Algorithm:
// Edge    Weight
// 0 - 1   2
// 1 - 2   3
// 0 - 3   6
// 1 - 4   5
