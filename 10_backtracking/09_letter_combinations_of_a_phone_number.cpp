/*
Problem: Letter Combinations of a Phone Number

Approach:
- Use backtracking to build combinations character by character
- Map each digit to its corresponding characters
- At each index, try all possible characters for that digit
- Backtrack after exploring each choice

Complexity:
- Time: O(4^n), where n is the length of digits
- Space: O(n), recursion stack and current string (excluding output)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> res;
    string temp;
    vector<string> digitToChar = {"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "qprs", "tuv", "wxyz"};

    void backtrack(int i, string& digits) {
        // full combination formed
        if (temp.size() == digits.size()) {
            res.push_back(temp);
            return;
        }

        // characters mapped to current digit
        string chars = digitToChar[digits[i] - '0'];

        for (char c : chars) {
            temp.push_back(c);        // choose
            backtrack(i + 1, digits); // explore next digit
            temp.pop_back();          // backtrack
        }
    }

    vector<string> letterCombinations(string digits) {
        // handle empty input
        if (digits.empty()) return res;

        backtrack(0, digits);
        return res;
    }
};
