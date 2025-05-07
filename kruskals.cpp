//Kruskals
#include <iostream>      // For input and output
#include <vector>        // To use dynamic arrays (vectors)
#include <algorithm>     // To sort the edges

using namespace std;

// Structure to store an edge with source, destination, and weight
struct Edge {
    int src, dest, weight;
};

// Function to compare two edges by their weight
// Used in sorting to get edges in increasing order
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// Function to find the parent (representative) of a node
// Used to check if two nodes are in the same set
int findParent(vector<int>& parent, int node) {
    // If node is its own parent, return it
    if (parent[node] == node)
        return node;

    // Else, recursively find the top parent
    // Also use path compression to make future lookups faster
    return parent[node] = findParent(parent, parent[node]);
}

// Function to unite (merge) two sets
void unionSets(vector<int>& parent, int a, int b) {
    int parentA = findParent(parent, a);
    int parentB = findParent(parent, b);

    // Make one root the parent of the other (joining the sets)
    parent[parentB] = parentA;
}

// Function to run Kruskal’s algorithm
void kruskal(int V, vector<Edge>& edges) {
    // Sort edges in increasing order of weight
    sort(edges.begin(), edges.end(), compare);

    // Create a parent array to track disjoint sets
    vector<int> parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i; // Initially, each node is its own parent

    int totalWeight = 0; // Total weight of MST

    cout << "\nEdges in the Minimum Spanning Tree:\n";
    for (Edge e : edges) {
        // Check if current edge connects different components
        if (findParent(parent, e.src) != findParent(parent, e.dest)) {
            // If yes, include the edge in MST
            cout << e.src << " - " << e.dest << "  (weight " << e.weight << ")\n";
            totalWeight += e.weight;

            // Merge the two sets
            unionSets(parent, e.src, e.dest);
        }
        // If it forms a cycle, we skip the edge
    }

    // Print total weight of MST
    cout << "Total weight of MST: " << totalWeight << endl;
}

// Main function
int main() {
    int V, E; // Number of vertices and edges

    cout << "Enter number of vertices and edges: ";
    cin >> V >> E; // User inputs number of vertices and edges

    vector<Edge> edges(E); // Vector to store edges

    // Input all the edges from the user
    cout << "Enter each edge (source destination weight):\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    // Run Kruskal’s algorithm
    kruskal(V, edges);

    return 0;
}

// Enter number of vertices and edges: 5 7
// Enter each edge (source destination weight):
// 0 1 2
// 0 3 6
// 1 2 3
// 1 3 8
// 1 4 5
// 2 4 7
// 3 4 9

// Edges in the Minimum Spanning Tree:
// 0 - 1  (weight 2)
// 1 - 2  (weight 3)
// 1 - 4  (weight 5)
// 0 - 3  (weight 6)
// Total weight of MST: 16