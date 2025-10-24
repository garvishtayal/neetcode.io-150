/*
Problem: Search in Rotated Sorted Array

Approach:
- First, find the index of the minimum element (rotation point) using binary search (`findMinIndex`):
    - Compare middle element with current minimum to update minIndex.
    - If left half is sorted, search right; else, search left.
- Determine which side of the rotation point the target lies in:
    - If target lies in left side, search between [0, minIndex-1].
    - If target lies in right side, search between [minIndex, n-1].
    - If target is outside both ranges, return -1.
- Perform standard binary search in the determined subarray.

Complexity:
- Time: O(log n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int findMinIndex(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;
        int minIndex = 0;

        while (l <= r) {
            if (nums[l] < nums[r]) {
                minIndex = (nums[l] < nums[minIndex]) ? l : minIndex;
                break;
            }

            int mid = l + (r - l) / 2;
            if (nums[mid] < nums[minIndex]) minIndex = mid;

            if (nums[l] <= nums[mid]) l = mid + 1;
            else r = mid - 1;
        }

        return minIndex;
    }

public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int miniIndex = findMinIndex(nums);
        int l = 0;
        int r = n - 1;

        if (miniIndex != 0) {
            if (nums[l] <= target && target <= nums[miniIndex - 1]) r = miniIndex - 1; // left side
            else if (nums[miniIndex] <= target && target <= nums[r]) l = miniIndex;    // right side
            else return -1; // target not present
        }

        // Standard binary search
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] < target) l = mid + 1;
            else r = mid - 1;
        }

        return -1;
    }
};
