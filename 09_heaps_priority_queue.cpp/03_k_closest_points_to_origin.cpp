/*
Problem: K Closest Points to Origin

Approach:
- Use a max-heap with a custom comparator based on squared distance
- Keep heap size limited to k while iterating through all points
- Remove the farthest point whenever heap size exceeds k
- Remaining points in the heap are the k closest to the origin

Complexity:
- Time: O(n log k), heap operations for each point
- Space: O(k), heap storing k points
*/

#include <bits/stdc++.h>
using namespace std;

struct Compare {
    bool operator()(vector<int> a, vector<int> b) {
        int distA = a[0]*a[0] + a[1]*a[1];
        int distB = b[0]*b[0] + b[1]*b[1];

        // max-heap based on distance
        return distA < distB;
    }
};

class Solution {
public:
    vector<vector<int>> res;

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        // process all points
        for (auto point : points) {
            pq.push(point);
            // keep only k closest points
            if (pq.size() > k) {
                pq.pop();
            }
        }

        // extract results from heap
        while (pq.size() != 0) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};
