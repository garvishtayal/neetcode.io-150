/*
Problem: Cheapest Flights Within K Stops

Approach:
- Build adjacency list for directed weighted graph
- Use min heap storing {cost, node, stops}
- Maintain dist[node][stops] to track minimum cost
- Expand only if stops <= k

Complexity:
- Time: O(E log V)
- Space: O(V * K)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        using T = tuple<int, int, int>; // cost, node, stops

        // build adj list
        vector<vector<pair<int,int>>> adj(n);
        for (auto &flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }

        priority_queue<T, vector<T>, greater<T>> pq;
        pq.push({0, src, 0});

        // dist[node][stops] = min cost
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        while (!pq.empty()) {
            auto [cost, u, stops] = pq.top();
            pq.pop();

            // reached destination
            if (u == dst) return cost;

            // exceed allowed stops
            if (stops > k) continue;

            for (auto [v, w] : adj[u]) {

                int newCost = cost + w;

                // relax if better cost with stops+1
                if (newCost < dist[v][stops + 1]) {
                    dist[v][stops + 1] = newCost;
                    pq.push({newCost, v, stops + 1});
                }
            }
        }

        return -1;
    }
};
