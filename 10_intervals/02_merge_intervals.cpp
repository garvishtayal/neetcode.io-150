/*
Problem: Merge Intervals

Approach:
- Sort intervals by starting time
- Iterate through intervals and compare with last added interval
- If no overlap, push current interval
- If overlap exists, merge by updating the end value

Complexity:
- Time: O(n log n), sorting dominates
- Space: O(n), result storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals based on start time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;

        // merge overlapping intervals
        for (auto &curr : intervals) {
            // if no overlap, add to result
            if (res.empty() || res.back()[1] < curr[0]) {
                res.push_back(curr);
            } 
            // overlap exists, merge intervals
            else {
                res.back()[1] = max(res.back()[1], curr[1]);
            }
        }

        return res;
    }
};
