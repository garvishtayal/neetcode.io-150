/*
Problem: Binary Search

Approach:
- Implement a recursive binary search function:
    - Base case: if start > end, return -1 (target not found).
    - Calculate mid index.
    - If nums[mid] == target, return mid.
    - If nums[mid] < target, search in the right half.
    - Else, search in the left half.
- The main `search` function initializes start and end indices and calls the recursive function.

Complexity:
- Time: O(log n), where n is the number of elements
- Space: O(log n) due to recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int binarySearch(vector<int>& nums, int target, int start, int end) {
        if (start > end) return -1;

        int mid = start + (end - start) / 2; // Avoid potential overflow

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return binarySearch(nums, target, mid + 1, end);
        else return binarySearch(nums, target, start, mid - 1);
    }

public:
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, target, 0, nums.size() - 1);
    }
};
