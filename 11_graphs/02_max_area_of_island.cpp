/*
Problem: Max Area of Island

Approach:
- Traverse the grid
- When an unvisited land cell (1) is found:
    - Run DFS to calculate the area of the island
    - Keep track of the maximum area found
- DFS returns the size of the connected component

Complexity:
- Time: O(m * n), each cell visited once
- Space: O(m * n), visited matrix + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // start DFS only from unvisited land
                if (grid[i][j] == 1 && !visited[i][j]) {
                    res = max(res, dfs(grid, visited, i, j));
                }
            }
        }

        return res;
    }

    int dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary + water + visited check
        if (i < 0 || j < 0 || i >= m || j >= n)
            return 0;
        if (grid[i][j] == 0 || visited[i][j])
            return 0;

        // mark current cell
        visited[i][j] = true;

        // count current cell + all connected land
        return 1
            + dfs(grid, visited, i + 1, j)
            + dfs(grid, visited, i - 1, j)
            + dfs(grid, visited, i, j + 1)
            + dfs(grid, visited, i, j - 1);
    }
};
