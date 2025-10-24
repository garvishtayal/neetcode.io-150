/*
Problem: Container With Most Water

Approach:
- Use two pointers, starting at the beginning (left) and end (right) of the array.
- Calculate the area formed by the two lines: (right - left) * min(height[left], height[right]).
- Update max area if the current area is larger.
- Move the pointer pointing to the shorter line inward, since moving the taller line cannot increase the area.
- Repeat until pointers meet.

Complexity:
- Time: O(n), where n is the number of lines
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area = 0;
        int l = 0;
        int r = heights.size() - 1;

        while (l < r) {
            int height = min(heights[l], heights[r]);
            int width = r - l;
            max_area = max(max_area, height * width);

            // Move the pointer pointing to the shorter line
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return max_area;
    }
};
