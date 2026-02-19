/*
Problem: Swim in Rising Water

Approach:
- Use Dijkstra’s algorithm on grid
- Each state stores minimum possible maximum elevation so far
- Use min heap to always expand smallest time first
- Relax edges using max(currDist, nextCellHeight)

Complexity:
- Time: O(n^2 log n)
- Space: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        
        using pii = pair<int, pair<int, int>>; // w -> (i,j)
        priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap based on w

        // source initialization
        dist[0][0] = grid[0][0];
        pq.push({grid[0][0], {0,0}});

        while (!pq.empty()) {
            auto [currDist, cell] = pq.top();
            auto [i, j] = cell;
            pq.pop();

            // reached destination
            if (i == n-1 && j == n-1) {
                return currDist;
            }

            // ignore outdated entries
            if (currDist > dist[i][j]) continue;

            // explore neighbors
            int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

            for (auto &d : dirs) {
                int ni = i + d[0];
                int nj = j + d[1];

                if (ni >= 0 && nj >= 0 && ni < n && nj < n) {

                    // edge relaxation
                    int newDist = max(currDist, grid[ni][nj]);

                    if (newDist < dist[ni][nj]) {
                        dist[ni][nj] = newDist;
                        pq.push({newDist, {ni, nj}});
                    }
                }
            }
        }

        return -1;
    }
};
