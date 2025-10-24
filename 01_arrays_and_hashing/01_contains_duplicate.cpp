/*
Problem: Contains Duplicate

Approach:
- Use a hash set to track seen values. If a value is seen twice, return true.

Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int n : nums) {
            if (seen.count(n)) return true;
            seen.insert(n);
        }
        return false;
    }
};
