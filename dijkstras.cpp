// A C++ program for Dijkstra's single source shortest path
// algorithm. The program is for adjacency matrix
// representation of the graph
#include <iostream>       // For input/output operations
#include <vector>         // For using dynamic arrays (vectors)
#include <limits.h>       // For using INT_MAX (maximum integer value)

using namespace std;

// A utility function to find the vertex with the minimum distance value
// from the set of vertices not yet included in the shortest path tree
int minDistance(const vector<int>& dist, const vector<bool>& sptSet, int V) {
    int min = INT_MAX;       // Initialize minimum value as infinite
    int min_index = -1;      // Index of the vertex with the minimum distance

    // Loop through all vertices to find the minimum distance vertex
    for (int v = 0; v < V; v++) {
        // If the vertex is not included in the shortest path tree
        // and its distance is smaller than the current minimum
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];   // Update minimum
            min_index = v;   // Update index
        }
    }
    return min_index;        // Return the index of the vertex with min distance
}

// Function to print the final shortest distances from the source vertex
void printSolution(const vector<int>& dist, int V) {
    cout << "\nVertex \tDistance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << "\t" << i << " \t\t\t " << dist[i] << "\n";
    }
}

// Function that implements Dijkstra's algorithm for a graph represented
// using adjacency matrix
void dijkstra(const vector<vector<int>>& graph, int src, int V) {
    vector<int> dist(V, INT_MAX);   // Initialize distances as infinite
    vector<bool> sptSet(V, false);  // Track vertices included in shortest path tree

    dist[src] = 0;                  // Distance from source to itself is always 0

    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet, V);  // Get vertex with minimum distance
        sptSet[u] = true;                      // Mark it as processed

        // Update distance value of the adjacent vertices of the picked vertex
        for (int v = 0; v < V; v++) {
            // Conditions to update dist[v]:
            // 1. Not in sptSet
            // 2. Edge from u to v exists (graph[u][v] != 0)
            // 3. u is reachable (dist[u] != INT_MAX)
            // 4. New distance is shorter
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];  // Update the distance
            }
        }
    }

    // Print the final distances
    printSolution(dist, V);
}

int main() {
    int V;  // Number of vertices
    cout << "Enter the number of vertices: ";
    cin >> V;

    // Create a 2D vector for the adjacency matrix of size VxV
    vector<vector<int>> graph(V, vector<int>(V));
    cout << "Enter the adjacency matrix (enter 0 if no edge between vertices):\n";

    // Input the adjacency matrix
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }

    int src;  // Source vertex
    cout << "Enter the source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    // Run Dijkstra's algorithm from the source vertex
    dijkstra(graph, src, V);

    return 0;  // Exit program
}

// Enter the number of vertices: 5
// Enter the adjacency matrix (enter 0 if no edge between vertices):
// 0 10 0 0 5
// 0 0 1 0 2
// 0 0 0 4 0
// 7 0 6 0 0
// 0 3 9 2 0
// Enter the source vertex (0 to 4): 0

// Vertex  Distance from Source
//     0                0
//     1                8
//     2                9
//     3                7
//     4                5
