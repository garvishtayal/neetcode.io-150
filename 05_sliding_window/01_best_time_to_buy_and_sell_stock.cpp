/*
Problem: Best Time to Buy and Sell Stock

Approach:
- Use two pointers: `l` (buy day) and `r` (sell day)
- If the price at `r` is higher than at `l`, calculate profit and update maxProfit
- Otherwise, move `l` to `r` since a lower buying price is found
- Continue until `r` reaches the end of the array

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0; // Buy pointer
        int r = 1; // Sell pointer
        int maxProfit = 0;

        while (r < prices.size()) {
            if (prices[l] < prices[r]) {
                maxProfit = max(maxProfit, prices[r] - prices[l]);
            } else {
                l = r;
            }
            r++;
        }

        return maxProfit;
    }
};
