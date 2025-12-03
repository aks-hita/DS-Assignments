#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

class DSU {
    vector<int> parent, rankv;
public:
    DSU(int n) {
        parent.resize(n);
        rankv.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (rankv[x] < rankv[y]) swap(x, y);
            parent[y] = x;
            if (rankv[x] == rankv[y]) rankv[x]++;
        }
    }
};

int main() {
    int n = 6;
    vector<Edge> edges = {
        {0, 1, 4},
        {0, 2, 4},
        {1, 2, 2},
        {1, 3, 5},
        {2, 3, 8},
        {3, 4, 6},
        {4, 5, 3},
        {3, 5, 7}
    };

    sort(edges.begin(), edges.end(), cmp);

    DSU dsu(n);
    vector<Edge> mst;
    int totalWeight = 0;

    for (auto &e : edges) {
        if (dsu.find(e.u) != dsu.find(e.v)) {
            mst.push_back(e);
            totalWeight += e.w;
            dsu.unite(e.u, e.v);
        }
    }

    cout << "Edges in MST:\n";
    for (auto &e : mst)
        cout << e.u << " - " << e.v << " : " << e.w << endl;

    cout << "Total Weight: " << totalWeight << endl;
    return 0;
}
