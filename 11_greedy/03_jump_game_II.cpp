/*
Problem: Jump Game II

Approach:
- Use greedy BFS-like level expansion
- Track the farthest index reachable in current range
- When reaching the end of current range, increment jumps
- Update range to the farthest reachable index

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0, end = 0, farthest = 0;

        // iterate until second last index
        for (int i = 0; i < nums.size() - 1; i++) {
            farthest = max(farthest, i + nums[i]);  // expand reachable range

            // when current range ends, make a jump
            if (i == end) {
                jumps++;
                end = farthest;
            }
        }

        return jumps;
    }
};
