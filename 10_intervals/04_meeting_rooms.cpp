/*
Problem: Meeting Rooms

Approach:
- If no meetings, return true
- Sort intervals by start time using custom comparator
- Compare each meeting’s start with previous meeting’s end
- If overlap found, return false

Complexity:
- Time: O(n log n), sorting dominates
- Space: O(1), no extra space used (excluding sort)
*/

#include <bits/stdc++.h>
using namespace std;

// Definition of Interval
class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // if no meetings, can attend all
        if (intervals.empty()) return true;

        // sort by start time
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });

        int last_end = intervals[0].end;

        // check for overlap
        for (int i = 1; i < intervals.size(); i++) {
            // no overlap
            if (intervals[i].start >= last_end) {
                last_end = intervals[i].end;
            } 
            // overlap found
            else {
                return false;
            }
        }

        return true;
    }
};
