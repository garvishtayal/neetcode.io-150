/*
Problem: Spiral Matrix

Approach:
- Maintain four boundaries: left, right, top, bottom
- Traverse top row → right column → bottom row → left column
- Shrink boundaries after each layer
- Stop when boundaries cross

Complexity:
- Time: O(m * n)
- Space: O(1) (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;

        int left = 0, right = matrix[0].size();
        int top = 0, bottom = matrix.size();

        while (left < right && top < bottom) {

            // traverse top row
            for (int i = left; i < right; i++) {
                res.push_back(matrix[top][i]);
            }
            top++;

            // traverse right column
            for (int i = top; i < bottom; i++) {
                res.push_back(matrix[i][right - 1]);
            }
            right--;

            // check if boundaries crossed
            if (!(left < right && top < bottom)) {
                break;
            }

            // traverse bottom row
            for (int i = right - 1; i >= left; i--) {
                res.push_back(matrix[bottom - 1][i]);
            }
            bottom--;

            // traverse left column
            for (int i = bottom - 1; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            left++;
        }

        return res;
    }
};