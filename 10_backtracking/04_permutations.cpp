/*
Problem: Permutations

Approach:
- Use backtracking to build permutations step by step
- Track which elements are already used with a boolean array
- When permutation size equals input size, store it
- Backtrack after exploring each choice

Complexity:
- Time: O(n! * n), generating all permutations
- Space: O(n), recursion stack + visited array (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> res;

    void backtrack(vector<int>& perm, vector<int>& nums, vector<bool>& pick) {
        // complete permutation formed
        if (perm.size() == nums.size()) {
            res.push_back(perm);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (!pick[i]) {
                perm.push_back(nums[i]);   // choose unused element
                pick[i] = true;             // mark as used
                backtrack(perm, nums, pick);
                perm.pop_back();            // backtrack
                pick[i] = false;            // unmark
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> pick(nums.size(), false);
        vector<int> perm;

        backtrack(perm, nums, pick);
        return res;
    }
};
