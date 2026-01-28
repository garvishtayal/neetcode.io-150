/*
Problem: Combination Sum II

Approach:
- Use backtracking to explore all unique combinations
- Sort the array to handle duplicates
- Skip duplicate elements at the same recursion level
- Move index forward to avoid reusing the same element

Complexity:
- Time: Exponential, depends on number of valid combinations
- Space: O(n), recursion stack (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<int> combin;

    void backtrack(int idx, vector<int>& arr, int tar) {
        // stop if target becomes negative
        if (tar < 0) return;

        // valid combination found
        if (tar == 0) {
            ans.push_back(combin);
            return;
        }

        for (int i = idx; i < arr.size(); i++) {
            // skip duplicate elements at same recursion level
            if (i > idx && arr[i] == arr[i - 1]) continue;

            combin.push_back(arr[i]);              // choose
            backtrack(i + 1, arr, tar - arr[i]);   // move forward, no reuse
            combin.pop_back();                     // backtrack
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort to group duplicates
        sort(candidates.begin(), candidates.end());

        backtrack(0, candidates, target);

        return ans;
    }
};
