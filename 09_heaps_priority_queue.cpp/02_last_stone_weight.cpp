/*
Problem: Last Stone Weight

Approach:
- Use a max-heap to always access the two heaviest stones
- Repeatedly remove the top two stones and smash them
- If their weights differ, push the remaining weight back
- Continue until at most one stone remains

Complexity:
- Time: O(n log n), heap operations for all stones
- Space: O(n), max-heap storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;

        // push all stones into max-heap
        for (int i = 0; i < stones.size(); i++)
            pq.push(stones[i]);

        // process until one or no stone remains
        while (pq.size() > 1) {
            int x = pq.top();  // heaviest stone
            pq.pop();
            int y = pq.top();  // second heaviest stone
            pq.pop();

            // if weights are different, push the remaining stone
            if (x == y) continue;
            pq.push(max(x, y) - min(x, y)); 
        }

        // if no stones left
        if (pq.size() == 0) return 0;

        // weight of the last remaining stone
        return pq.top();
    }
};
