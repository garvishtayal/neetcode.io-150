/*
Problem: N-Queens

Approach:
- Use backtracking to place queens row by row
- For each cell, check if placing a queen is safe
- Validate column and both diagonals
- Backtrack after exploring each valid placement

Complexity:
- Time: Exponential, explores all valid board configurations
- Space: O(n^2) for board + O(n) recursion stack (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> board;
    vector<vector<string>> ans;

    bool isSafe(vector<string>& board, int row, int col, int n) {
        // check current row
        for (int j = 0; j < n; j++) {
            if (board[row][j] == 'Q') return false;
        }

        // check current column
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q') return false;
        }

        // check left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        // check right diagonal
        for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }

        return true;
    }

    void backtrack(vector<string>& board, int row, int n, vector<vector<string>>& ans) {
        // all queens placed
        if (row == n) {
            ans.push_back(board);
            return;
        }

        for (int j = 0; j < n; j++) {
            if (isSafe(board, row, j, n)) {
                board[row][j] = 'Q';          // place queen
                backtrack(board, row + 1, n, ans);
                board[row][j] = '.';          // backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        backtrack(board, 0, n, ans);

        return ans;
    }
};
