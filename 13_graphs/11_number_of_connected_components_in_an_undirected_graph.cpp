/*
Problem: Number of Connected Components in an Undirected Graph

Approach:
- Build an undirected adjacency list
- Use DFS to traverse each connected component
- Each new DFS call represents one connected component

Complexity:
- Time: O(n + e), where e = number of edges
- Space: O(n), visited array + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<bool>& vis) {
        // mark node as visited
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                dfs(v, adj, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        // build undirected graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;

        // count connected components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        return components;
    }
};
