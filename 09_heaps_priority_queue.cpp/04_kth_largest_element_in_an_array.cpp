/*
Problem: Kth Largest Element in an Array

Approach:
- Use a min-heap to keep track of the k largest elements
- Push each element into the heap while iterating
- If heap size exceeds k, remove the smallest element
- The top of the heap represents the kth largest element

Complexity:
- Time: O(n log k), heap operations for all elements
- Space: O(k), min-heap storage
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        // edge case: empty input
        if (nums.empty()) return 0;

        // maintain a min-heap of size k
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }

        // top of min-heap is kth largest element
        return minHeap.top();
    }
};
