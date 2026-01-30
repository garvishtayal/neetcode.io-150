/*
Problem: Word Search

Approach:
- Try starting DFS from every cell matching the first character
- Use DFS to explore 4-directional neighbors
- Track visited cells using a set to avoid revisits in current path
- Backtrack after each DFS path exploration

Complexity:
- Time: O(m * n * 4^k), where k = length of the word
- Space: O(k), recursion stack + path set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ROWS, COLS;
    set<pair<int, int>> path;

    bool exist(vector<vector<char>>& board, string word) {
        ROWS = board.size();
        COLS = board[0].size();

        // try starting DFS from every cell
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (board[r][c] == word[0]) {
                    if (dfs(board, word, r, c, 0)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i) {
        // all characters matched
        if (i == word.length()) return true;

        // boundary, mismatch, or already visited
        if (r < 0 || c < 0 || r >= ROWS || c >= COLS ||
            board[r][c] != word[i] || path.count({r, c})) {
            return false;
        }

        // mark current cell as visited in path
        path.insert({r, c});

        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);

        // backtrack
        path.erase({r, c});

        return res;
    }
};
