/*
Problem: Trapping Rain Water

Approach:
- Use two pointers (left and right) to traverse the height array from both ends.
- Maintain `maxLeft` and `maxRight` to store the maximum height seen from left and right.
- At each step, move the pointer with the smaller height:
    - Add the difference between the max height on that side and current height to the total water trapped.
- Continue until pointers meet.

Complexity:
- Time: O(n), where n is the number of bars
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int total_water = 0;

        int maxLeft = 0;
        int maxRight = 0;

        while (l < r) {
            if (height[l] <= height[r]) {
                maxLeft = max(maxLeft, height[l]);
                total_water += maxLeft - height[l];
                l++;
            } else {
                maxRight = max(maxRight, height[r]);
                total_water += maxRight - height[r];
                r--;
            }
        }

        return total_water;
    }
};
