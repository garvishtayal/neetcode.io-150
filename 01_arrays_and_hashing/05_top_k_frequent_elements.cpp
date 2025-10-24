/*
Problem: Top K Frequent Elements

Approach:
- Count frequencies using a hash map
- Sort by frequency using ordered map
- Return top k elements

Complexity:
- Time: O(n log n)
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> output;
        map<int, int> freqHash;
        for(int i = 0; i < nums.size(); i++) {
            freqHash[nums[i]]++;
        }

        map<int, vector<int>, greater<int>> freqHashReversed;
        for(auto &p : freqHash) {
            freqHashReversed[p.second].push_back(p.first);
        }

        int count = 0;
        for(auto &p : freqHashReversed) {
            for(int num : p.second) {
                if(count < k) {
                    output.push_back(num);
                    count++;
                }
            }
        }
        
        return output;
    }
};
