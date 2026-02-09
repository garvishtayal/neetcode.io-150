/*
Problem: Task Scheduler

Approach:
- Count frequency of each task
- Use a max-heap to always schedule the task with highest remaining count
- Use a queue to track tasks in cooldown with their next available time
- Simulate time units until all tasks are completed

Complexity:
- Time: O(n log 26) ≈ O(n), where n is number of tasks
- Space: O(26 + n), heap and cooldown queue
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        // count frequency of each task
        for (char task : tasks) {
            count[task - 'A']++;
        }

        // max-heap for task frequencies
        priority_queue<int> maxHeap;
        for (int cnt : count) {
            if (cnt > 0) {
                maxHeap.push(cnt);
            }
        }

        int time = 0;
        // queue to handle cooldown: {remaining count, available time}
        queue<pair<int, int>> q;

        // process until all tasks are done
        while (!maxHeap.empty() || !q.empty()) {
            time++;

            // if no task available, jump time to next available task
            if (maxHeap.empty()) {
                time = q.front().second;
            }
            else {
                int cnt = maxHeap.top() - 1;
                maxHeap.pop();

                // if task still has remaining count, put it in cooldown
                if (cnt > 0) 
                    q.push({cnt, time + n});
            }

            // move task from cooldown back to heap if ready
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};
