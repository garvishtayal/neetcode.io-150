/*
Problem: Longest Repeating Character Replacement

Approach:
- Use sliding window with two pointers `l` and `r`
- Keep a frequency map of characters in the current window
- Track the count of the most frequent character (`maxf`)
- If window size minus `maxf` exceeds `k`, shrink the window from left
- Update the result with the maximum window size found

Complexity:
- Time: O(n)
- Space: O(1) (since only uppercase letters are used)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> count;
        int res = 0;

        int l = 0, maxf = 0;
        for (int r = 0; r < s.size(); r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
