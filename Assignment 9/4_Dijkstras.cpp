#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int minDist(vector<int>& dist, vector<bool>& visited, int n) {
    int m = numeric_limits<int>::max(), idx = -1;
    for (int i = 0; i < n; i++)
        if (!visited[i] && dist[i] < m)
            m = dist[i], idx = i;
    return idx;
}

void dijkstra(vector<vector<int>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);

    dist[src] = 0;

    for (int c = 0; c < n - 1; c++) {
        int u = minDist(dist, visited, n);
        visited[u] = true;

        for (int v = 0; v < n; v++)
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }

    for (int i = 0; i < n; i++)
        cout << "Distance from " << src << " to " << i << " = " << dist[i] << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 2},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 2, 14, 10, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
