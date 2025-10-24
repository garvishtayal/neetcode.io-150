/*
Problem: Search a 2D Matrix

Approach:
- Treat the 2D matrix as a set of sorted rows.
- Perform binary search on the rows (`colSearch`) to find the row that could contain the target:
    - Check if target lies between the first and last elements of the row.
- Perform binary search within that row (`rowSearch`) to find the target.
- Return true if found, false otherwise.

Complexity:
- Time: O(log m + log n), where m = number of rows, n = number of columns
- Space: O(log m + log n), due to recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int colSearch(vector<vector<int>>& matrix, int start, int end, int target) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;

        if (target >= matrix[mid][0] && target <= matrix[mid][matrix[0].size() - 1]) {
            return mid;
        } else if (target < matrix[mid][0]) {
            return colSearch(matrix, start, mid - 1, target);
        } else {
            return colSearch(matrix, mid + 1, end, target);
        }
    }

    int rowSearch(vector<int>& row, int start, int end, int target) {
        if (start > end) return -1;
        int mid = start + (end - start) / 2;

        if (row[mid] == target) return mid;
        else if (row[mid] < target) return rowSearch(row, mid + 1, end, target);
        else return rowSearch(row, start, mid - 1, target);
    }

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int targetCol = colSearch(matrix, 0, matrix.size() - 1, target);
        if (targetCol == -1) return false;

        int rowResult = rowSearch(matrix[targetCol], 0, matrix[0].size() - 1, target);
        return rowResult != -1;
    }
};
