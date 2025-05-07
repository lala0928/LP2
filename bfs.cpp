// BFS algorithm in C++

#include <iostream>  // For input-output operations
#include <list>      // For using lists (adjacency list for the graph)
#include <queue>     // For using the queue in BFS
#include <vector>    // For using vectors to store parent and visited info
#include <algorithm>

using namespace std;

class Graph {
    int numVertices;         // The number of vertices in the graph
    list<int>* adjLists;     // An array of lists to store the adjacency lists

public:
    Graph(int vertices);     // Constructor to initialize the graph with a given number of vertices
    void addEdge(int src, int dest);  // Method to add an edge between two vertices
    void BFS(int startVertex, int endVertex);  // Method to find the shortest path using BFS
};

// Constructor to create a graph with 'vertices' number of vertices
Graph::Graph(int vertices) {
    numVertices = vertices;            // Set the number of vertices
    adjLists = new list<int>[vertices]; // Create an array of adjacency lists for each vertex
}

// Method to add an edge between two vertices (bi-directional for an undirected graph)
void Graph::addEdge(int src, int dest) {
    adjLists[src].push_back(dest);   // Add 'dest' to the adjacency list of 'src'
    adjLists[dest].push_back(src);   // Add 'src' to the adjacency list of 'dest' (because it's undirected)
}

// BFS function to find the shortest path between start and end vertices
void Graph::BFS(int startVertex, int endVertex) {
    // Create a vector of booleans to track visited vertices, initialized to false
    vector<bool> visited(numVertices, false);
    
    // Create a vector to store the parent of each vertex (used to trace the path)
    vector<int> parent(numVertices, -1); // -1 means no parent yet

    // Queue to store the vertices for BFS traversal
    queue<int> q;

    visited[startVertex] = true; // Mark the start vertex as visited
    q.push(startVertex);         // Push the start vertex into the queue

    // Start BFS traversal
    while (!q.empty()) {
        int currVertex = q.front(); // Get the front vertex in the queue
        q.pop();                    // Remove the front vertex from the queue

        if (currVertex == endVertex)  // If we've reached the end vertex, stop the traversal
            break;

        // Explore all neighbors of the current vertex
        for (int adjVertex : adjLists[currVertex]) {
            if (!visited[adjVertex]) { // If the adjacent vertex is not visited
                visited[adjVertex] = true;    // Mark it as visited
                parent[adjVertex] = currVertex; // Set the current vertex as its parent
                q.push(adjVertex);             // Push the adjacent vertex into the queue for later exploration
            }
        }
    }

    // If the endVertex was not reached, there's no path
    if (!visited[endVertex]) {
        cout << "No path found from " << startVertex << " to " << endVertex << endl;
        return;
    }

    // Reconstruct the shortest path by following parent pointers
    vector<int> path;
    for (int v = endVertex; v != -1; v = parent[v]) {
        path.push_back(v);  // Add each vertex in the path to the vector
    }

    // Reverse the path to start from the start vertex
    reverse(path.begin(), path.end());

    // Print the shortest path
    cout << "Shortest path from " << startVertex << " to " << endVertex << ": ";
    for (int v : path) {
        cout << v << " ";  // Print each vertex in the path
    }
    cout << endl;
}

// Main function where the user provides input and the BFS algorithm is called
int main() {
    int vertices, edges;
    
    // Ask the user for the number of vertices and edges in the graph
    cout << "Enter number of vertices: ";
    cin >> vertices;

    // Create a graph object with the specified number of vertices
    Graph g(vertices);

    // Ask the user for the number of edges
    cout << "Enter number of edges: ";
    cin >> edges;
    cout << "Enter edges (src dest):" << endl;

    // Get the edges from the user and add them to the graph
    for (int i = 0; i < edges; i++) {
        int src, dest;
        cin >> src >> dest; // Get each edge
        g.addEdge(src, dest);  // Add the edge to the graph
    }

    // Ask the user for the start and end vertices to find the shortest path
    int start, end;
    cout << "Enter start and end vertices to find shortest path: ";
    cin >> start >> end;

    // Call the BFS function to find and print the shortest path
    g.BFS(start, end);

    return 0;
}


// Enter number of vertices: 4
// Enter number of edges: 5
// Enter edges (src dest):
// 0 1
// 0 2
// 1 2
// 2 3
// 3 3
// Enter start and end vertices to find shortest path: 0 3

// Shortest path from 0 to 3: 0 2 3






//DFS

#include <bits/stdc++.h>  // Includes all standard C++ libraries
using namespace std;      // So we don’t need to write std:: before standard functions

// Class representing a directed graph using adjacency list representation
class Graph {
public:
    map<int, bool> visited;           // Keeps track of visited nodes during DFS
    map<int, list<int>> adj;          // Adjacency list: each node maps to a list of its neighbors

    void addEdge(int v, int w);       // Method to add a directed edge from v to w
    void DFS(int v);                  // Method to perform DFS traversal starting from vertex v
};

// Adds a directed edge from vertex v to vertex w
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);  // Add w to v's list of adjacent vertices
}

// Recursive DFS function starting from vertex v
void Graph::DFS(int v) {
    visited[v] = true;    // Mark current node as visited
    cout << v << " ";     // Print the visited node

    // Recur for all unvisited neighbors of v
    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])    // If the neighbor hasn't been visited
            DFS(*i);         // Recursively call DFS for the neighbor
}

int main() {
    Graph g;            // Create an instance of the Graph class
    int edges;          // Number of edges to be input
    int v, w;           // Variables to store each edge (from v to w)
    int start;          // Starting vertex for DFS

    cout << "Enter the number of edges: ";
    cin >> edges;       // Take input for the number of edges

    cout << "Enter edges in the format (from to):\n";
    for (int i = 0; i < edges; ++i) {   // Loop to input all edges
        cin >> v >> w;    // Take input for a directed edge from v to w
        g.addEdge(v, w);  // Add the edge to the graph
    }

    cout << "Enter starting vertex for DFS: ";
    cin >> start;       // Take input for the starting vertex

    cout << "Following is Depth First Traversal (starting from vertex " << start << "):\n";
    g.DFS(start);       // Perform DFS traversal from the starting vertex

    return 0;           // End of program
}


// Enter the number of edges: 6
// Enter edges in the format (from to):
// 0 1
// 0 2
// 1 2
// 2 0
// 2 3
// 3 3
// Enter starting vertex for DFS: 2
// Following is Depth First Traversal (starting from vertex 2):
// 2 0 1 3