/*
Problem: Insert Interval

Approach:
- Use binary search to find correct insertion index for newInterval
- Insert newInterval into intervals at that position
- Iterate through intervals and merge overlapping ones
- Build result by comparing with last inserted interval

Complexity:
- Time: O(n), insertion + single pass merge
- Space: O(n), result storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {

        // binary search insertion position
        int l = 0, r = intervals.size();

        while (l < r) {
            int m = (l + r) / 2;
            if (intervals[m][0] < newInterval[0])
                l = m + 1;
            else
                r = m;
        }

        intervals.insert(intervals.begin() + l, newInterval);
        // ----

        vector<vector<int>> res;

        // merge overlapping intervals
        for (auto &curr : intervals) {
            // no overlap
            if (res.empty() || res.back()[1] < curr[0]) {
                res.push_back(curr);
            } 
            // overlap, merge intervals
            else {
                res.back()[1] = max(res.back()[1], curr[1]);
            }
        }

        return res;
    }
};
