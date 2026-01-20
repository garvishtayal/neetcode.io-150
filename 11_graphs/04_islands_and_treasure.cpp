/*
Problem: Islands and Treasure

Approach:
- Use multi-source BFS
- Push all treasure cells (value = 0) into the queue initially
- Expand BFS level by level to fill shortest distance to treasure
- Update only unvisited land cells (INT_MAX)

Complexity:
- Time: O(m * n), each cell processed once
- Space: O(m * n), queue for BFS
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // push all treasure cells into queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        vector<vector<int>> dirs = {
            {-1, 0}, {1, 0}, {0, -1}, {0, 1}
        };

        // BFS traversal
        while (!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int r = row + dirs[i][0];
                int c = col + dirs[i][1];

                // boundary check + skip non-empty cells
                if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] != INT_MAX)
                    continue;

                // update distance and push to queue
                grid[r][c] = grid[row][col] + 1;
                q.push({r, c});
            }
        }
    }
};
