/*
Problem: Minimum Window Substring

Approach:
- Use a sliding window with two pointers `l` and `r`
- Maintain two hash maps:
    - `countT` to store required character frequencies from `t`
    - `window` to store current window character frequencies
- `need` represents the number of unique characters required
- `have` tracks how many required characters currently satisfy the frequency condition
- Expand the window by moving `r`:
    - Update window frequency
    - If a character meets the required frequency, increment `have`
- When `have == need`, try shrinking the window from the left:
    - Update the result if the current window is smaller
    - Reduce frequency of left character
    - If a required character falls below needed frequency, decrement `have`
- Continue until the smallest valid window is found

Complexity:
- Time: O(n), where n = length of string `s`
- Space: O(1), since the hashmap size is bounded by character set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT, window;
        for (char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for (int r = 0; r < s.length(); r++) {
            char c = s[r];
            window[c]++;

            if (countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while (have == need) {
                if ((r - l + 1) < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if (countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
        }

        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};
