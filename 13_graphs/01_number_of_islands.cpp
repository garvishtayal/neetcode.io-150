/*
Problem: Number of Islands

Approach:
- Iterate through the grid
- When a land cell ('1') is found that is not visited:
    - Run DFS to mark the entire island as visited
    - Increment island count
- DFS explores connected land in all 4 directions

Complexity:
- Time: O(m * n), each cell visited once
- Space: O(m * n), visited matrix + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {

                // skip water or already visited cells
                if (grid[i][j] == '0' || visited[i][j] == true)
                    continue;

                // DFS consumes one full island
                dfs(grid, visited, i, j);
                res++;
            }
        }

        return res;
    }

    void dfs(auto &grid, auto &visited, int i, int j) {
        int m = grid.size();
        int n = grid[0].size();

        // boundary + water + visited check
        if (i < 0 || j < 0 || i >= m || j >= n)
            return;
        if (grid[i][j] == '0' || visited[i][j])
            return;

        // mark current cell
        visited[i][j] = true;

        // explore 4 directions
        dfs(grid, visited, i + 1, j);
        dfs(grid, visited, i - 1, j);
        dfs(grid, visited, i, j + 1);
        dfs(grid, visited, i, j - 1);
    }
};
