/*
Problem: 3Sum

Approach:
- Sort the input array.
- Iterate through each number as the first element of the triplet.
  - Skip duplicates for the first element.
- Use two pointers (left and right) to find pairs that sum to the negative of the first element.
  - Skip duplicates for left and right elements.
- Add valid triplets to the result vector.

Complexity:
- Time: O(n^2), due to the outer loop and two-pointer traversal
- Space: O(1) extra space (excluding the result vector)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for (int i = 0; i < nums.size(); i++) {
            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            int target = -nums[i];
            int l = i + 1;
            int r = nums.size() - 1;

            while (l < r) {
                int sum = nums[l] + nums[r];

                if (sum == target) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    // Skip duplicate left and right elements
                    while (l < r && nums[l] == nums[l + 1]) l++;
                    while (l < r && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                } else if (sum < target) {
                    l++;
                } else {
                    r--;
                }
            }
        }

        return res;
    }
};
