/*
Problem: Product of Array Except Self

Approach:
- First pass: Calculate prefix products from left to right
- Second pass: Multiply by suffix products from right to left
- Result[i] = product of all elements except nums[i]

Complexity:
- Time: O(n)
- Space: O(1) excluding output array
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1);
        
        long long prefix = 1;
        for(int i = 0; i < n; i++) {
            res[i] = prefix;
            prefix = prefix * nums[i];
        }
        
        long long suffix = 1;
        for(int i = n-1; i >= 0; i--) {
            res[i] = res[i] * suffix;
            suffix = suffix * nums[i];
        }
        
        return res;
    }
};