/*
Problem: Min Cost Climbing Stairs

Approach:
- Define dp[i] as minimum cost to reach step i
- Base cases: dp[0] = cost[0], dp[1] = cost[1]
- Transition: dp[i] = min(dp[i-1], dp[i-2]) + cost[i]
- Final answer is min(dp[n-1], dp[n-2])

Complexity:
- Time: O(n)
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n);

        // base cases
        dp[0] = cost[0];
        dp[1] = cost[1];

        // bottom-up DP
        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
        }

        // choose last or second last step
        return min(dp[n - 1], dp[n - 2]);
    }
};
