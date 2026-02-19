/*
Problem: Combination Sum

Approach:
- Use backtracking to explore all combinations
- At each index, try including the current number
- Allow multiple inclusion of the same number
- Use a set to avoid duplicate combinations

Complexity:
- Time: Exponential, depends on recursion paths
- Space: O(n) recursion stack + set for unique combinations
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<vector<int>> s;

    void backtrack(int idx, vector<int>& arr, int tar,
                   vector<vector<int>>& ans, vector<int>& combin) {
        // stop if index out of bounds or target becomes negative
        if (idx == arr.size() || tar < 0) return;

        // valid combination found
        if (tar == 0) {
            if (s.find(combin) == s.end()) {
                ans.push_back(combin);
                s.insert(combin);
            }
            return;
        }

        // include current element
        combin.push_back(arr[idx]);

        // take current element once
        backtrack(idx + 1, arr, tar - arr[idx], ans, combin);

        // take current element multiple times
        backtrack(idx, arr, tar - arr[idx], ans, combin);

        // backtrack
        combin.pop_back();

        // exclude current element
        backtrack(idx + 1, arr, tar, ans, combin);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> combin;

        backtrack(0, nums, target, ans, combin);

        return ans;
    }
};
