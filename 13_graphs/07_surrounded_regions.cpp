/*
Problem: Surrounded Regions

Approach:
- Traverse the board
- For each unvisited 'O', run BFS to collect its connected component
- Track whether the component touches the boundary
- If it does NOT touch the boundary, flip all cells in the component to 'X'

Complexity:
- Time: O(m * n), each cell visited once
- Space: O(m * n), visited matrix + BFS queue
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    int m, n;

    void bfs(int r, int c, vector<vector<bool>>& visited,
             vector<vector<char>>& board) {

        queue<pair<int,int>> q;
        vector<pair<int,int>> component;
        bool touchesBoundary = false;

        q.push({r, c});
        visited[r][c] = true;

        // BFS to collect one connected component
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            component.push_back({x, y});

            // check if component touches boundary
            if (x == 0 || y == 0 || x == m - 1 || y == n - 1)
                touchesBoundary = true;

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx >= 0 && ny >= 0 && nx < m && ny < n &&
                    !visited[nx][ny] && board[nx][ny] == 'O') {

                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        // flip only fully surrounded components
        if (!touchesBoundary) {
            for (auto &cell : component) {
                board[cell.first][cell.second] = 'X';
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // process each cell
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (board[r][c] == 'O' && !visited[r][c])
                    bfs(r, c, visited, board);
            }
        }
    }
};
