/*
Problem: Sliding Window Maximum

Approach:
- Use a max-heap (priority_queue) storing pairs of {value, index}
- Iterate through the array and push each element with its index into the heap
- Once the window size reaches `k`:
    - Remove elements from the heap that are outside the current window
      (index <= i - k)
    - The top of the heap represents the maximum element in the current window
- Append the maximum to the output for each valid window

Complexity:
- Time: O(n log n)
  - Each element is pushed once and popped at most once
- Space: O(n) for the heap
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int, int>> heap;
        vector<int> output;

        for (int i = 0; i < nums.size(); i++) {
            heap.push({nums[i], i});

            if (i >= k - 1) {
                while (heap.top().second <= i - k) {
                    heap.pop();
                }
                output.push_back(heap.top().first);
            }
        }
        return output;
    }
};
