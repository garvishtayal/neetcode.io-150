/*
Problem: Hand of Straights

Approach:
- If total cards not divisible by groupSize, return false
- Use ordered map to maintain frequency of cards
- Always start forming group from smallest available card
- Try to build consecutive sequence of length groupSize
- Reduce frequency and erase when count becomes zero

Complexity:
- Time: O(n log n)
- Space: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        // total cards must be divisible by group size
        if (hand.size() % groupSize != 0) return false;

        map<int, int> freq;

        // build frequency map
        for (int card : hand) {
            freq[card]++;
        }

        // process until all cards are used
        while (!freq.empty()) {
            int start = freq.begin()->first; // smallest card available

            // try to form one group of consecutive cards
            for (int i = 0; i < groupSize; i++) {
                int card = start + i;

                // if required card not available
                if (freq[card] == 0) {
                    return false;
                }

                freq[card]--;

                // remove card from map if count becomes zero
                if (freq[card] == 0) {
                    freq.erase(card);
                }
            }
        }

        return true;
    }
};
