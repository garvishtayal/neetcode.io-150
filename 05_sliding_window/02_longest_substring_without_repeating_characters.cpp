/*
Problem: Longest Substring Without Repeating Characters

Approach:
- Use sliding window with two pointers `l` (left) and `r` (right)
- Maintain a set to track characters in the current window
- If a duplicate is found, move `l` forward and remove characters until duplicate is gone
- Update maximum length after each iteration

Complexity:
- Time: O(n)
- Space: O(min(n, a)) where a = size of the character set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        set<char> set;
        int length = 0;

        for (int r = 0; r < s.size(); r++) {
            while (set.find(s[r]) != set.end()) {
                set.erase(s[l]);
                l++;
            }

            set.insert(s[r]);
            length = max(length, (int)set.size());
        }

        return length;
    }
};
