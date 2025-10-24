/*
Problem: Generate Parentheses

Approach:
- Use backtracking to generate all valid combinations of n pairs of parentheses.
- Maintain a stack to build current combination:
    - Can add '(' if the number of open parentheses < n.
    - Can add ')' if the number of close parentheses < number of open parentheses.
- When open == n and close == n, add the current combination to the result.

Complexity:
- Time: O(4^n / sqrt(n)), Catalan number of combinations
- Space: O(n) for recursion stack and O(number of combinations) for result
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    stack<char> s;
    vector<string> result;

    void fillStack(int open, int close, int n) {
        if (open == n && close == n) {
            // Copy stack content to string (without popping)
            string str;
            stack<char> temp = s;
            while (!temp.empty()) {
                str += temp.top();
                temp.pop();
            }
            reverse(str.begin(), str.end());
            result.push_back(str);
            return;
        }

        if (open < n) {
            s.push('(');
            fillStack(open + 1, close, n);
            s.pop();
        }

        if (close < open) {
            s.push(')');
            fillStack(open, close + 1, n);
            s.pop();
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        fillStack(0, 0, n);
        return result;
    }
};
