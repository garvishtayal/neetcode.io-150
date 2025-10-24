/*
Problem: Evaluate Reverse Polish Notation (RPN)

Approach:
- Use a stack to evaluate the expression.
- Maintain a map of operators to their corresponding lambda functions.
- Iterate through tokens:
    - If token is an operator:
        - Pop the top two elements from the stack.
        - Apply the operator and push the result back.
    - If token is a number, convert it to integer and push onto the stack.
- At the end, the stack contains the final result.

Complexity:
- Time: O(n), where n is the number of tokens
- Space: O(n), for the stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        unordered_map<char, function<int(int,int)>> opMap = {
            {'+', [](int a, int b) { return a + b; }},
            {'-', [](int a, int b) { return a - b; }},
            {'*', [](int a, int b) { return a * b; }},
            {'/', [](int a, int b) { return a / b; }}
        };

        for (const string& token : tokens) {
            if (token.size() == 1 && opMap.count(token[0])) {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();
                st.push(opMap[token[0]](a, b));
            } else {
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};
