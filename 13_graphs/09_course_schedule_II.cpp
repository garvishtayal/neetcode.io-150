/*
Problem: Course Schedule II

Approach:
- Build adjacency list from prerequisites
- Use DFS to perform topological sort
- Detect cycles using recursion stack
- If a cycle exists, return empty ordering
- Otherwise, reverse DFS postorder to get valid course order

Complexity:
- Time: O(V + E), V = courses, E = prerequisites
- Space: O(V), recursion stack + visited arrays
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(int u, vector<vector<int>>& adj,
             vector<bool>& vis, vector<bool>& rec, vector<int>& res) {

        // mark node as visited and in recursion stack
        vis[u] = true;
        rec[u] = true;

        for (int v : adj[u]) {
            if (!vis[v]) {
                if (dfs(v, adj, vis, rec, res))
                    return true;    // cycle detected
            }
            else if (rec[v]) {
                return true;        // back-edge found
            }
        }

        // remove from recursion stack and add to result
        rec[u] = false;
        res.push_back(u);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> res;

        // build adjacency list
        for (auto &e : prerequisites)
            adj[e[1]].push_back(e[0]);

        vector<bool> vis(numCourses, false);
        vector<bool> rec(numCourses, false);

        // DFS on all components
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i])
                if (dfs(i, adj, vis, rec, res))
                    return {};
        }

        // reverse postorder gives topological order
        reverse(res.begin(), res.end());
        return res;
    }
};
