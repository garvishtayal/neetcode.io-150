/*
Problem: Merge Triplets to Form Target Triplet

Approach:
- Ignore triplets that exceed target in any dimension
- For valid triplets, check if any position matches target
- Track matched indices using a set
- If all three indices are matched, return true

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        // iterate through triplets
        for (const auto& t : triplets) {
            // skip if triplet exceeds target
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            // check if any position matches target
            for (int i = 0; i < t.size(); i++) {
                if (t[i] == target[i]) {
                    good.insert(i);
                }
            }
        }

        // all three indices must be matched
        return good.size() == 3;
    }
};
