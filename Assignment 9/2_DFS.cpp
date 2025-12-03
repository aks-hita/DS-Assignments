#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int n;
    vector<vector<int>> adj;

    void dfsUtil(int u, vector<bool>& visited) {
        visited[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!visited[v])
                dfsUtil(v, visited);
    }

public:
    Graph(int v) : n(v) {
        adj.assign(n, vector<int>());
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void DFS(int start) {
        vector<bool> visited(n, false);
        dfsUtil(start, visited);
    }
};

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    cout << "DFS starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
