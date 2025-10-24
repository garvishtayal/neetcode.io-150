/*
Problem: Two Sum II - Input Array Is Sorted

Approach:
- Use two pointers starting from the beginning and end of the array.
- Calculate the sum of numbers at both pointers.
  - If sum equals target, return the 1-based indices.
  - If sum is less than target, move left pointer to the right.
  - If sum is greater than target, move right pointer to the left.
- Return empty vector if no solution exists (guaranteed one solution in problem).

Complexity:
- Time: O(n), where n is the size of the array
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;

        while (l < r) {
            int sum = numbers[l] + numbers[r];
            
            if (sum == target) 
                return {l + 1, r + 1};  // 1-based indices

            if (sum < target) 
                l++;
            else 
                r--;
        }

        return {};
    }
};
