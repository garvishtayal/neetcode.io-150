/*
Problem: Valid Parenthesis String

Approach:
- Maintain a range [leftMin, leftMax] of possible open brackets
- '(' increases both leftMin and leftMax
- ')' decreases both
- '*' can be '(', ')' or empty → decrease leftMin and increase leftMax
- If leftMax becomes negative → invalid
- Clamp leftMin to 0 and finally check leftMin == 0

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0, leftMax = 0;

        // iterate through string
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } 
            else if (c == ')') {
                leftMin--;
                leftMax--;
            }
            else {  // '*'
                leftMin--;   // treat as ')'
                leftMax++;   // treat as '('
            }

            // too many closing brackets
            if (leftMax < 0) return false;

            // leftMin cannot be negative
            if (leftMin < 0) leftMin = 0;
        }

        // valid if no mandatory unmatched '('
        return leftMin == 0;
    }
};
