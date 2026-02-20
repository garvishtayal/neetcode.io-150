/*
Problem: Climbing Stairs

Approach:
- Define dp[i] as number of ways to reach step i
- Base cases: dp[0] = 1, dp[1] = 1
- Transition: dp[i] = dp[i-1] + dp[i-2]
- Classic Fibonacci style DP

Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);

        // base cases
        dp[0] = 1;
        dp[1] = 1;

        // bottom-up DP
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }
};
