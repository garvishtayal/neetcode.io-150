/*
Problem: Largest Rectangle in Histogram

Approach:
- Use a stack to keep track of bars and their starting indices.
- Iterate through the histogram:
    - If the current bar is shorter than the bar at the top of the stack:
        - Pop bars from the stack and calculate area using their height and width (current index - start index).
        - Update max area.
    - Push the current bar with its starting index.
- After iteration, pop remaining bars and calculate area extending to the end of the histogram.
- Return the maximum area found.

Complexity:
- Time: O(n), each bar is pushed and popped at most once
- Space: O(n), for the stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st; // {start index, height}
        int maxArea = 0;

        for (int i = 0; i < heights.size(); i++) {
            int start = i;

            while (!st.empty() && heights[i] < st.top().second) {
                start = st.top().first;
                int height = st.top().second;
                st.pop();
                maxArea = max(maxArea, height * (i - start));
            }

            st.push({start, heights[i]});
        }

        while (!st.empty()) {
            int index = st.top().first;
            int height = st.top().second;
            maxArea = max(maxArea, height * ((int)heights.size() - index));
            st.pop();
        }

        return maxArea;
    }
};
