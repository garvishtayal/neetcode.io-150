/*
Problem: Palindrome Partitioning

Approach:
- Use backtracking to try all possible partitions
- At each position, check every possible substring
- Only proceed if the substring is a palindrome
- Backtrack after exploring each valid partition

Complexity:
- Time: Exponential, all possible partitions with palindrome checks
- Space: O(n), recursion stack and current path (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<string> path;

    bool isPalindrome(string& s, int l, int r) {
        // check if substring s[l..r] is palindrome
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void backtrack(string& s, int start) {
        // reached end of string, store current partition
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            // proceed only if current substring is palindrome
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(s, end + 1);
                path.pop_back();  // backtrack
            }
        }
    }

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return result;
    }
};
