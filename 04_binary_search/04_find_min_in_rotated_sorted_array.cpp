/*
Problem: Find Minimum in Rotated Sorted Array

Approach:
- Use binary search to find the minimum element in a rotated sorted array.
- At each step:
    - If nums[l] < nums[r], the subarray is sorted; update result with nums[l] and break.
    - Otherwise, calculate mid and update result with nums[mid].
    - If nums[l] <= nums[mid], minimum is in the right half → move l = mid + 1.
    - Else, minimum is in the left half → move r = mid - 1.
- Return the minimum value found.

Complexity:
- Time: O(log n), where n is the number of elements
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int res = nums[0];

        while (l <= r) {
            if (nums[l] < nums[r]) {
                res = min(res, nums[l]);
                break;
            }

            int mid = l + (r - l) / 2;
            res = min(res, nums[mid]);

            if (nums[l] <= nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }
};
