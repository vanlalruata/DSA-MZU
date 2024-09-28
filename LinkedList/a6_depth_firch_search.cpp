//C++ implementation of Depth-First Search (DFS) for a graph. This implementation will include both recursive and iterative approaches using a stack.

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
private:
    int vertices;                         // Number of vertices
    vector<vector<int>> adjacencyList;   // Adjacency list representation

public:
    // Constructor
    Graph(int v) {
        vertices = v;
        adjacencyList.resize(v);
    }

    // Function to add an edge to the graph
    void addEdge(int u, int v) {
        adjacencyList[u].push_back(v);   // Add v to u’s list
        adjacencyList[v].push_back(u);   // Add u to v’s list (for undirected graph)
    }

    // Recursive DFS function
    void dfsRecursive(int start) {
        vector<bool> visited(vertices, false);  // Keep track of visited nodes
        cout << "DFS (Recursive): ";
        dfsUtil(start, visited);
        cout << endl;
    }

    // Utility function for recursive DFS
    void dfsUtil(int vertex, vector<bool>& visited) {
        visited[vertex] = true;                  // Mark the current node as visited
        cout << vertex << " ";                   // Print the visited node

        // Recur for all the vertices adjacent to this vertex
        for (int adj : adjacencyList[vertex]) {
            if (!visited[adj]) {
                dfsUtil(adj, visited);           // Recur for the adjacent node
            }
        }
    }

    // Iterative DFS function
    void dfsIterative(int start) {
        vector<bool> visited(vertices, false);  // Keep track of visited nodes
        stack<int> s;                            // Stack for DFS
        s.push(start);                           // Push the starting vertex onto the stack

        cout << "DFS (Iterative): ";
        while (!s.empty()) {
            int vertex = s.top();
            s.pop();

            if (!visited[vertex]) {
                visited[vertex] = true;         // Mark the current node as visited
                cout << vertex << " ";          // Print the visited node
            }

            // Push all adjacent vertices onto the stack
            for (auto it = adjacencyList[vertex].rbegin(); it != adjacencyList[vertex].rend(); ++it) {
                if (!visited[*it]) {
                    s.push(*it);                 // Push unvisited adjacent node onto the stack
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

    // Perform DFS
    g.dfsRecursive(0);  // Start DFS from vertex 0
    g.dfsIterative(0);  // Start DFS from vertex 0

    return 0;
}
