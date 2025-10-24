/*
Problem: Daily Temperatures

Approach:
- Use a monotonic decreasing stack to keep track of temperatures and their indices.
- Iterate through the temperatures:
    - While the current temperature is higher than the temperature at the top of the stack:
        - Pop from the stack and calculate the difference in indices to determine the number of days until a warmer temperature.
    - Push the current temperature and its index onto the stack.
- Temperatures that never see a warmer day remain 0 in the result vector.

Complexity:
- Time: O(n), each element is pushed and popped at most once
- Space: O(n), for the stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<pair<int, int>> st; // {temperature, index}

        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > st.top().first) {
                res[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i], i});
        }

        return res;
    }
};
