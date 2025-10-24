/*
Problem: Longest Consecutive Sequence

Approach:
- Store numbers in ordered map for automatic sorting
- Traverse map and count consecutive sequences
- Track the longest sequence found

Complexity:
- Time: O(n log n) due to ordered map
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;

        map<int, int> hashmap;
        for(int i = 0; i < nums.size(); i++) {
            hashmap[nums[i]] = i;
        }
        
        vector<int> consecutiveCounts;
        int count = 1;
        int curElement = hashmap.begin()->first;
        int lastElement = hashmap.rbegin()->first;

        while(true) {
            if(curElement == lastElement) {
                consecutiveCounts.push_back(count);
                break;
            }

            if(hashmap.count(curElement + 1)) {
                curElement++;
                count++;
            } else {
                consecutiveCounts.push_back(count);
                count = 1;
                auto it = hashmap.find(curElement);
                curElement = (++it)->first;
            }
        }

        int maxCount = 0;
        for(int c : consecutiveCounts) {
            maxCount = max(maxCount, c);
        }
        
        return maxCount;
    }
};
