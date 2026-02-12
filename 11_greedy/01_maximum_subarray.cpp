/*
Problem: Maximum Subarray

Approach:
- Use Kadane’s Algorithm
- Maintain a running sum (curSum)
- If running sum becomes negative, reset to 0
- Track the maximum sum seen so far

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curSum = 0;
        int maxSum = nums[0];

        // iterate through array
        for (int num : nums) {
            // reset if current sum becomes negative
            if (curSum < 0) 
                curSum = 0;
                
            curSum = curSum + num;          // expand subarray
            maxSum = max(maxSum, curSum);  // update max
        }

        return maxSum;
    }
};
