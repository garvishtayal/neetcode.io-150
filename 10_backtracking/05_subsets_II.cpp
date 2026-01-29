/*
Problem: Subsets II

Approach:
- Use backtracking (DFS) to generate all subsets
- Sort the array to group duplicate elements
- Skip duplicates at the same recursion level
- Store the current subset at every recursion step

Complexity:
- Time: O(2^n * n), all subsets with copy cost
- Space: O(n), recursion stack (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int idx, vector<int>& nums, vector<int>& temp) {
        // store current subset
        ans.push_back(temp);

        for (int i = idx; i < nums.size(); i++) {
            // skip duplicates at same level
            if (i > idx && nums[i] == nums[i - 1]) continue;

            temp.push_back(nums[i]);   // choose
            dfs(i + 1, nums, temp);    // explore
            temp.pop_back();           // backtrack
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort to handle duplicates
        sort(nums.begin(), nums.end());

        vector<int> temp;
        dfs(0, nums, temp);

        return ans;
    }
};
