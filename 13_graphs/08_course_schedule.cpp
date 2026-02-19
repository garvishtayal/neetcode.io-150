/*
Problem: Course Schedule

Approach:
- Build adjacency list from prerequisites
- Use DFS to detect cycles in a directed graph
- Maintain:
    - vis[]  → globally visited nodes
    - rec[]  → nodes in current recursion stack
- If a back-edge is found (rec[v] == true), a cycle exists

Complexity:
- Time: O(V + E), V = courses, E = prerequisites
- Space: O(V), recursion stack + visited arrays
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj,
             vector<bool>& vis, vector<bool>& rec) {

        // mark node as visited and in recursion stack
        vis[u] = true;
        rec[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, adj, vis, rec))
                    return true;    // cycle detected
            }
            else if (rec[v]) {
                return true;        // back-edge found
            }
        }

        // remove node from recursion stack
        rec[u] = false;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // build adjacency list
        for (auto &e : prerequisites)
            adj[e[0]].push_back(e[1]);

        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);

        // check each component for cycles
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i])
                if (dfs(i, adj, vis, rec))
                    return false;
        }

        return true;
    }
};
