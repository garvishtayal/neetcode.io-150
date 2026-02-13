/*
Problem: Gas Station

Approach:
- First check if total gas is less than total cost → impossible
- Traverse stations while maintaining running fuel balance
- If balance becomes negative, reset start position to next station
- Greedy: the valid start must be after any failed segment

Complexity:
- Time: O(n)
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // if total gas < total cost, no solution
        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0)) {
            return -1;
        }

        int total = 0;
        int res = 0;

        // greedy traversal
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];

            // if current start fails, move start forward
            if (total < 0) {
                res = i + 1;
                total = 0;
            }
        }

        return res;
    }
};
