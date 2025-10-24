/*
Problem: Min Stack

Approach:
- Use two stacks:
    1. `stack` to store all values.
    2. `minStack` to store the minimum value at each level.
- Push:
    - Push value to `stack`.
    - Push the minimum between the value and current top of `minStack` to `minStack`.
- Pop:
    - Pop from both `stack` and `minStack`.
- Top:
    - Return top of `stack`.
- GetMin:
    - Return top of `minStack`.

Complexity:
- Time: O(1) for push, pop, top, and getMin
- Space: O(n), where n is the number of elements in the stack
*/

#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> minSt;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        int minVal = min(val, minSt.empty() ? val : minSt.top());
        minSt.push(minVal);
    }

    void pop() {
        st.pop();
        minSt.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};
