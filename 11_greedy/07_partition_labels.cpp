/*
Problem: Partition Labels

Approach:
- Record the last occurrence index of each character
- Traverse the string while tracking the farthest last occurrence (z)
- Increase current partition size
- When current index reaches z, finalize partition and reset size

Complexity:
- Time: O(n)
- Space: O(1), at most 26 characters
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        // map each character to its last occurrence
        unordered_map<char, int> mp;
        for (int i = 0; i < s.length(); i++) 
            mp[s[i]] = i;

        int size = 0;
        int z = 0;
        vector<int> res;

        // iterate through string
        for (int i = 0; i < s.length(); i++)  {
            z = max(z, mp[s[i]]);  // update farthest boundary
            size++;

            // if current index reaches boundary, close partition
            if (i == z) {
                res.push_back(size);
                size = 0;
            }
        }

        return res;
    }
};
