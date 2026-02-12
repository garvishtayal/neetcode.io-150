/*
Problem: Minimum Interval to Include Each Query

Approach:
- Sort queries while keeping original indices
- Sort intervals by start time
- Use a min-heap storing {interval_size, interval_end}
- For each query:
    • Add intervals whose start <= query
    • Remove intervals whose end < query
    • Top of heap gives smallest valid interval

Complexity:
- Time: O((n + q) log n)
- Space: O(n + q)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {

        // store queries with original index
        vector<pair<int,int>> sortedQueries;
        for (int i = 0; i < queries.size(); i++)
            sortedQueries.push_back({queries[i], i});

        // sort queries and intervals
        sort(sortedQueries.begin(), sortedQueries.end());
        sort(intervals.begin(), intervals.end());

        // min-heap based on interval size
        auto compare = [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> minH(compare);

        vector<int> res(queries.size(), -1);
        int idx = 0;
        int size;

        // sweep through sorted queries
        for (auto q : sortedQueries) {

            // Step 1: Add intervals whose start <= current query
            while (
                idx < intervals.size() &&
                intervals[idx][0] <= q.first
            ) {
                size = intervals[idx][1] - intervals[idx][0] + 1;
                minH.push({size, intervals[idx][1]});
                idx++;
            }

            // Step 2: Remove intervals that cannot contain the query
            while (
                !minH.empty() &&
                minH.top()[1] < q.first
            ) {
                minH.pop();
            }

            // Step 3: Assign smallest valid interval size
            if (!minH.empty()) 
                res[q.second] = minH.top()[0];
        }

        return res;
    }
};
