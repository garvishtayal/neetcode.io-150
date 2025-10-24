/*
Problem: Koko Eating Bananas

Approach:
- Use binary search to find the minimum eating speed k.
- Lower bound: 1 (slowest possible speed)
- Upper bound: max(piles) (fastest possible speed)
- For each candidate speed mid:
    - Calculate total hours needed to eat all piles at speed mid.
    - If total hours <= h, try a smaller speed (move right bound left).
    - Else, increase speed (move left bound right).
- Return the minimum speed that allows finishing in h hours.

Complexity:
- Time: O(n * log m), where n = number of piles, m = max pile size
- Space: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int res = r;

        while (l <= r) {
            int mid = l + (r - l) / 2;
            int totalHours = 0;

            for (int pile : piles) {
                totalHours += (pile + mid - 1) / mid; // ceiling division
            }

            if (totalHours <= h) {
                res = mid;
                r = mid - 1; // try slower speed
            } else {
                l = mid + 1; // need faster speed
            }
        }

        return res;
    }
};
