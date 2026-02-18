/*
Problem: Min Cost to Connect All Points

Approach:
- Generate all possible edges with Manhattan distance
- Sort edges by weight
- Use Kruskal’s algorithm with DSU
- Add edge if it does not create a cycle

Complexity:
- Time: O(n^2 log n)
- Space: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class DSU {
public:
    vector<int> parent;

    DSU(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); // initialize each node as its own parent
    }

    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]); // path compression
    }

    bool union_sets(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a == b) return false; // cycle detected
        parent[b] = a;
        return true;
    }
};

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<int>> edges;

        // build all edges with Manhattan distance
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int dist = abs(points[i][0] - points[j][0]) +
                           abs(points[i][1] - points[j][1]);
                edges.push_back({dist, i, j});
            }
        }

        sort(edges.begin(), edges.end()); // sort by weight

        DSU dsu(n);

        int cost = 0, used = 0;

        // Kruskal’s algorithm
        for (auto &e : edges) {
            if (dsu.union_sets(e[1], e[2])) {
                cost += e[0];
                used++;
                if (used == n - 1) break; // MST complete
            }
        }

        return cost;
    }
};
