/*
Problem: Jump Game

Approach:
- Work backwards from the last index (goal)
- For each index, check if it can reach the current goal
- If yes, update goal to current index (greedy step)
- At the end, check if goal moved back to index 0

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;
        int req = 0;

        // traverse backwards
        for (int i = nums.size() - 2; i >= 0; i--) {
            req = goal - i;

            // greedy choice: can current index reach goal?
            if (nums[i] >= req) {
                goal = i;
            }
        }

        return goal == 0;
    }
};
