/*
Problem: Pacific Atlantic Water Flow

Approach:
- Run DFS from all Pacific border cells
- Run DFS from all Atlantic border cells
- DFS only moves to cells with height >= previous cell
- A cell is valid if it can reach both oceans

Complexity:
- Time: O(m * n), each cell visited at most twice
- Space: O(m * n), visited matrices + recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    void dfs(int r, int c,
             vector<vector<int>>& heights,
             vector<vector<bool>>& visited)
    {
        int m = heights.size();
        int n = heights[0].size();

        // mark current cell reachable
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dirs[i][0];
            int nc = c + dirs[i][1];

            // boundary check
            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            // already visited
            if (visited[nr][nc])
                continue;

            // cannot flow uphill restriction
            if (heights[nr][nc] < heights[r][c])
                continue;

            dfs(nr, nc, heights, visited);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific ocean borders
        for (int c = 0; c < n; c++)
            dfs(0, c, heights, pacific);

        for (int r = 0; r < m; r++)
            dfs(r, 0, heights, pacific);

        // Atlantic ocean borders
        for (int c = 0; c < n; c++)
            dfs(m - 1, c, heights, atlantic);

        for (int r = 0; r < m; r++)
            dfs(r, n - 1, heights, atlantic);

        vector<vector<int>> result;

        // cells reachable from both oceans
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (pacific[r][c] && atlantic[r][c])
                    result.push_back({r, c});
            }
        }

        return result;
    }
};
