/*
Problem: Redundant Connection

Approach:
- Build an undirected graph
- Use DFS to detect a cycle
- Track the cycle nodes using cycleStart and a set
- Traverse edges from back to front to find the last edge
  that connects two nodes in the cycle

Complexity:
- Time: O(n), where n = number of edges
- Space: O(n), adjacency list + recursion stack + cycle set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<bool> visit;
    vector<vector<int>> adj;
    unordered_set<int> cycle;
    int cycleStart;

public:
    bool dfs(int node, int par) {
        // cycle detected
        if (visit[node]) {
            cycleStart = node;
            return true;
        }

        visit[node] = true;

        for (int nei : adj[node]) {
            if (nei == par)
                continue;

            if (dfs(nei, node)) {
                // collect nodes belonging to the cycle
                if (cycleStart != -1)
                    cycle.insert(node);

                if (node == cycleStart) {
                    cycleStart = -1;
                }
                return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);

        // build undirected graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        visit.resize(n + 1, false);
        cycleStart = -1;

        // detect cycle
        dfs(1, -1);

        // return the last edge that forms the cycle
        for (int i = edges.size() - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycle.count(u) && cycle.count(v)) {
                return {u, v};
            }
        }
        return {};
    }
};
