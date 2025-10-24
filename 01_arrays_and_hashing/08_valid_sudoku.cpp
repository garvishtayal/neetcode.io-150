/*
Problem: Valid Sudoku

Approach:
- Use separate hash maps for rows, columns, and 3x3 boxes
- Check each cell's digit against these maps
- If any digit appears twice in same row/col/box, return false

Complexity:
- Time: O(1) - fixed 9x9 board
- Space: O(1) - fixed size hash maps
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_map<char, int>> hashRow(9);
        vector<unordered_map<char, int>> hashColumn(9);
        vector<unordered_map<char, int>> hashSquare(9);

        // Check rows and fill row hash map
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                hashRow[i][board[i][j]]++;
            }
        }

        // Check columns and fill column hash map
        for(int i = 0; i < 9; i++) {
            for(auto row : board) {
                if(row[i] == '.') continue;
                hashColumn[i][row[i]]++;
            }
        }

        // Check 3x3 boxes and fill square hash map
        int squareIndex = 0;
        for(int i = 0; i < 9; i++) {
            if(i > 3) squareIndex = 0;
            if(i >= 3 && i < 6) squareIndex = 3;
            if(i >= 6 && i < 9) squareIndex = 6;

            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                
                if(j < 3) hashSquare[squareIndex][board[i][j]]++;
                else if(j < 6) hashSquare[squareIndex+1][board[i][j]]++;
                else hashSquare[squareIndex+2][board[i][j]]++;
            }
        }

        // Validate all constraints
        for(int i = 0; i < 9; i++) {
            for(char ch : board[i]) {
                if(ch != '.') {
                    int val = ch - '0';
                    if(val < 1 || val > 9) return false;
                }
            }

            for(auto &p : hashRow[i])
                if(p.second > 1) return false;
            for(auto &p : hashColumn[i])
                if(p.second > 1) return false;
            for(auto &p : hashSquare[i])
                if(p.second > 1) return false;
        }

        return true;
    }
};
