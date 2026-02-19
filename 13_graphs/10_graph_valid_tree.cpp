/*
Problem: Graph Valid Tree

Approach:
- Build an undirected adjacency list
- Use DFS to detect cycles
- Track parent node to avoid false cycle detection
- Count connected components
- Graph is a valid tree if:
    - No cycles exist
    - Exactly one connected component

Complexity:
- Time: O(n + e), where e = number of edges
- Space: O(n), visited array + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int u, int parent, vector<vector<int>>& adj,
             vector<bool>& vis) {

        // mark node as visited
        vis[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, u, adj, vis))
                    return true;    // cycle detected
            }
            else if (v != parent) {
                return true;        // visited non-parent neighbor
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);

        // build undirected graph
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;

        // check for cycles and count components
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                if (dfs(i, -1, adj, vis))
                    return false;
            }
        }

        // valid tree must have exactly one component
        return components == 1;
    }
};
