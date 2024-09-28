//C++ implementation of Breadth-First Search (BFS) for a graph using an adjacency list representation. BFS explores the neighbor nodes at the present depth prior to moving on to nodes at the next depth level.

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int vertices;                          // Number of vertices
    vector<vector<int>> adjacencyList;    // Adjacency list representation

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjacencyList.resize(v);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);    // Add v to u’s list
        adjacencyList[v].push_back(u);    // Add u to v’s list (for undirected graph)
    }

    // BFS function
    void bfs(int start) {
        vector<bool> visited(vertices, false); // Keep track of visited nodes
        queue<int> q;                           // Queue for BFS

        visited[start] = true;                  // Mark the starting node as visited
        q.push(start);                          // Enqueue the starting node

        cout << "BFS: ";
        while (!q.empty()) {
            int vertex = q.front();             // Get the front vertex
            q.pop();                            // Dequeue the front vertex
            cout << vertex << " ";              // Print the visited vertex

            // Traverse all adjacent vertices
            for (int adj : adjacencyList[vertex]) {
                if (!visited[adj]) {
                    visited[adj] = true;        // Mark as visited
                    q.push(adj);                // Enqueue the adjacent vertex
                }
            }
        }
        cout << endl;
    }
};

// Main function
int main() {
    Graph g(6);  // Create a graph with 6 vertices

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    // Perform BFS
    g.bfs(0);  // Start BFS from vertex 0

    return 0;
}
