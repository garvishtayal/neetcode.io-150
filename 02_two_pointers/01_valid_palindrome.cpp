/*
Problem: Valid Palindrome

Approach:
- Use two pointers from the start and end of the string.
- Skip non-alphanumeric characters.
- Compare characters in a case-insensitive manner.
- If any mismatch is found, return false; otherwise, return true.

Complexity:
- Time: O(n), where n is the length of the string
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;

        while (l < r) {
            // Move left pointer to next alphanumeric character
            while (l < r && !isAlphaNum(s[l])) l++;
            // Move right pointer to previous alphanumeric character
            while (l < r && !isAlphaNum(s[r])) r--;

            // Case-insensitive comparison
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

private:
    // Check if character is alphanumeric
    bool isAlphaNum(char c) {
        return (c >= 'A' && c <= 'Z') ||
               (c >= 'a' && c <= 'z') ||
               (c >= '0' && c <= '9');
    }
};
