/*
Problem: Rotting Oranges

Approach:
- Use multi-source BFS
- Push all initially rotten oranges into the queue
- Each BFS level represents one minute
- Rot all adjacent fresh oranges
- Track remaining fresh oranges

Complexity:
- Time: O(m * n), each cell processed once
- Space: O(m * n), queue for BFS
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // push all rotten oranges and count fresh ones
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }

        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        int time = 0;

        // BFS minute by minute
        while (!q.empty() && fresh > 0) {
            int sz = q.size();   // one minute passes
            time++;

            for (int i = 0; i < sz; i++) {
                auto [row, col] = q.front();
                q.pop();

                // rot all 4-directional neighbors
                for (int i = 0; i < 4; i++) {
                    int r = row + dirs[i][0];
                    int c = col + dirs[i][1];

                    if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != 1)
                        continue;

                    grid[r][c] = 2;
                    fresh--;
                    q.push({r, c});
                }
            }
        }

        // if fresh oranges remain, return -1
        return fresh == 0 ? time : -1;
    }
};
