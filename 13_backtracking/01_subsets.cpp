/*
Problem: Subsets

Approach:
- Use backtracking (DFS) to generate all subsets
- Store the current subset at every recursion level
- Iterate from the current index to avoid duplicates
- Backtrack after exploring each choice

Complexity:
- Time: O(2^n * n), all subsets with copy cost
- Space: O(n), recursion stack (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;

        dfs(0, nums, temp, ans);
        return ans;
    }

    void dfs(int idx, vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans) {
        // store current subset
        ans.push_back(temp);

        // try all choices starting from idx
        for (int i = idx; i < nums.size(); i++) {

            temp.push_back(nums[i]);        // choose
            dfs(i + 1, nums, temp, ans);    // explore
            temp.pop_back();                // backtrack
        }
    }
};
