/*
Problem: Network Delay Time

Approach:
- Build adjacency list for directed weighted graph
- Apply Dijkstra's algorithm using min heap
- Perform edge relaxation to update shortest distances
- Return maximum distance among all nodes

Complexity:
- Time: O(E log V)
- Space: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // build graph (u -> {v, weight})
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& time : times) {
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);

        // min heap {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // source initialization
        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            // skip if we already found better distance
            if (currDist > dist[u]) continue;

            for (auto [v, w] : adj[u]) {
                // edge relaxation
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
