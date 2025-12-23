/*
Problem: Find the Duplicate Number

Approach:
- Use Floyd’s Tortoise and Hare (Cycle Detection) algorithm
- Treat the array as a linked list:
    - Index represents the node
    - nums[i] represents the next pointer
- Phase 1:
    - Move `slow` by one step and `fast` by two steps
    - They will meet inside the cycle
- Phase 2:
    - Reset `slow` to index 0
    - Move both pointers one step at a time
    - The meeting point is the duplicate number

Complexity:
- Time: O(n)
- Space: O(1), constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int slow = 0, fast = 0;

        // Phase 1: Detect cycle
        while (true) {
            slow = nums[slow];
            fast = nums[nums[fast]];

            if (slow == fast) {
                break;
            }
        }

        // Phase 2: Find entrance to the cycle
        slow = 0;
        while (true) {
            slow = nums[slow];
            fast = nums[fast];

            if (slow == fast) {
                return slow;
            }
        }
    }
};
