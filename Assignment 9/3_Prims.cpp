#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int minKey(vector<int>& key, vector<bool>& mstSet, int n) {
    int minVal = numeric_limits<int>::max(), index = -1;
    for (int i = 0; i < n; i++)
        if (!mstSet[i] && key[i] < minVal)
            minVal = key[i], index = i;
    return index;
}

void primMST(vector<vector<int>>& graph, int n) {
    vector<int> parent(n);
    vector<int> key(n, numeric_limits<int>::max());
    vector<bool> mstSet(n, false);

    key[0] = 0;
    parent[0] = -1;

    for (int c = 0; c < n - 1; c++) {
        int u = minKey(key, mstSet, n);
        mstSet[u] = true;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    cout << "Edges in MST:\n";
    int total = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " - " << i << " : " << graph[i][parent[i]] << endl;
        total += graph[i][parent[i]];
    }
    cout << "Total Weight: " << total << endl;
}

int main() {
    vector<vector<int>> graph = {
        {0, 4, 0, 0, 0, 0},
        {4, 0, 8, 0, 0, 0},
        {0, 8, 0, 7, 0, 4},
        {0, 0, 7, 0, 9, 14},
        {0, 0, 0, 9, 0, 10},
        {0, 0, 4, 14, 10, 0}
    };

    int n = graph.size();
    primMST(graph, n);

    return 0;
}
