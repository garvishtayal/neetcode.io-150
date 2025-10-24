/*
Problem: Two Sum

Approach:
- Store each number's index in a hash map
- For each number, check if (target - num) exists in map
- Return indices if complement found with different index

Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hash;
        for(int i = 0; i < nums.size(); i++) {
            hash[nums[i]] = i;
        }
        
        for(int i = 0; i < nums.size(); i++) {
            if(hash.count(target-nums[i]) && i != hash[target-nums[i]]) {
                return {i, hash[target-nums[i]]};
            }
        }
        return {};
    }
};
