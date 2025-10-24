/*
Problem: Valid Parentheses

Approach:
- Use a stack to keep track of opening brackets.
- Create a map for closing-to-opening bracket pairs.
- Iterate through the string:
    - If the character is a closing bracket:
        - Check if stack is empty → invalid.
        - Check if top of stack matches corresponding opening bracket → pop it.
        - Else → invalid.
    - If character is an opening bracket → push onto stack.
- After iteration, stack should be empty for the string to be valid.

Complexity:
- Time: O(n), where n is the length of the string
- Space: O(n), for the stack and map
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> bracketPair = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (bracketPair.count(c)) { // Closing bracket
                if (st.empty() || st.top() != bracketPair[c]) {
                    return false;
                }
                st.pop();
            } else { // Opening bracket
                st.push(c);
            }
        }

        return st.empty();
    }
};
