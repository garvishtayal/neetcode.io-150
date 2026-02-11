/*
Problem: Non-overlapping Intervals

Approach:
- Sort intervals by starting time
- Track the end of the last non-overlapping interval
- If current interval overlaps, increment removal count
- Keep the interval with smaller end to minimize future conflicts

Complexity:
- Time: O(n log n), sorting dominates
- Space: O(1), no extra space used (excluding sort)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // sort intervals by start time
        sort(intervals.begin(), intervals.end());

        int c = 0;
        int last_end = intervals[0][1];

        // iterate through intervals
        for (int i = 1; i < intervals.size(); i++) {
            // no overlap
            if (intervals[i][0] >= last_end) {
                last_end = intervals[i][1];
            } 
            // overlap found
            else {
                c++;
                // keep interval with smaller end
                last_end = min(last_end, intervals[i][1]);
            }
        }

        return c;
    }
};
