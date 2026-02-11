/*
Problem: Meeting Rooms II

Approach:
- If no meetings, return 0
- Sort intervals by start time
- Use a min-heap to track the earliest ending meeting
- If current meeting starts after earliest end, reuse that room
- Heap size represents number of rooms required

Complexity:
- Time: O(n log n), sorting + heap operations
- Space: O(n), heap storage
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
    int minMeetingRooms(vector<Interval>& intervals) {
        // no meetings
        if (intervals.empty()) return 0;

        // sort by start time
        sort(intervals.begin(), intervals.end(),
            [](const Interval& a, const Interval& b) {
                return a.start < b.start;
            });

        // min-heap to track meeting end times
        priority_queue<int, vector<int>, greater<int>> minH;

        // first meeting takes one room
        minH.push(intervals[0].end);

        for (int i = 1; i < intervals.size(); i++) {
            // if room is free, reuse it
            if (intervals[i].start >= minH.top()) {
               minH.pop();
            }

            // allocate room (new or reused)
            minH.push(intervals[i].end);
        }

        // number of rooms needed
        return minH.size();
    }
};
