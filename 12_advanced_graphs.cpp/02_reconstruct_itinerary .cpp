/*
Problem: Reconstruct Itinerary

Approach:
- Build adjacency list from tickets (src -> destinations)
- Sort each destination list to maintain lexical order
- Use DFS (Hierholzer’s algorithm) consuming edges
- Add node post DFS call to build itinerary in reverse

Complexity:
- Time: O(E log E)
- Space: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {

        // build graph
        unordered_map<string, vector<string>> adj;
        for (auto& ticket : tickets) {
            adj[ticket[0]].emplace_back(ticket[1]);
        }

        // sort destinations to ensure lexical order
        for (auto& [src, dests] : adj) {
            sort(dests.begin(), dests.end());
        }

        vector<string> result;
        dfs("JFK", adj, result);

        reverse(result.begin(), result.end());
        return result;
    }

    void dfs(const string& node,
             unordered_map<string, vector<string>>& adj,
             vector<string>& result) {

        auto& dests = adj[node];

        // consume edges using DFS
        while (!dests.empty()) {
            string next = dests.front();
            dests.erase(dests.begin()); // consume edge
            dfs(next, adj, result);
        }

        // post-order insertion
        result.push_back(node);
    }
};
