#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph
{
    int V;                   // Number of vertices
    vector<vector<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Add an edge between vertices u and v
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u); // Since it's an undirected graph
    }

    // Depth First Search (recursive)
    void DFSUtil(int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " "; // Print the current vertex

        // Recursive call for all the vertices adjacent to this vertex
        for (int u : adj[v])
        {
            if (!visited[u])
            {
                DFSUtil(u, visited);
            }
        }
    }

    // Depth First Search
    void DFS(int start)
    {
        vector<bool> visited(V, false);
        DFSUtil(start, visited);
    }

    // Breadth First Search
    void BFS(int start)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " "; // Print the current vertex

            // Visit all adjacent vertices of v
            for (int u : adj[v])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
    }
};

int main()
{
    int V, E; // Number of vertices and edges
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create a graph
    Graph g(V);

    // Add edges
    cout << "Enter the edges (vertex pairs):" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v;
        cout << "Enter Source:";
        cin >> u;
        cout << "Enter destination:";
        cin >> v;
        g.addEdge(u, v);
    }

    int startVertex;
    cout << "Enter the starting vertex for traversal: ";
    cin >> startVertex;

    cout << "Depth First Search (DFS): ";
    g.DFS(startVertex);
    cout << endl;

    cout << "Breadth First Search (BFS): ";
    g.BFS(startVertex);
    cout << endl;

    return 0;
}
