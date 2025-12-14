/*
Problem: Permutation in String

Approach:
- Use a sliding window over `s2`
- Maintain a frequency hashmap of characters from `s1`
- Use two pointers `l` and `r` to represent the window
- `matchesFound` keeps track of how many required characters are matched
- While expanding the window:
    - If current character is still needed (hashmap value > 0), increment `matchesFound`
    - Decrement its frequency in the hashmap
- When the window size reaches `s1.size()`, shrink it from the left:
    - If the left character was contributing to a match (hashmap value >= 0), decrement `matchesFound`
    - Restore its frequency and move `l`
- If at any point `matchesFound == s1.size()`, a valid permutation exists

Complexity:
- Time: O(n), where n = length of s2
- Space: O(1), since the hashmap stores at most 26 lowercase letters
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        unordered_map<char, int> hashmap;
        for(int i=0; i<s1.size(); i++) hashmap[s1[i]]++;

        int l = 0;
        int matchesFound  = 0;
        
        for(int r=0; r<s2.size(); r++) {

            if(hashmap[s2[r]] > 0) matchesFound++;
            hashmap[s2[r]]--;

            if(matchesFound == s1.size()) return true;
            
            // shrink window
            if((r-l+1) == s1.size()) {
                if(hashmap[s2[l]] >= 0) matchesFound--;
                hashmap[s2[l]]++;
                l++;
            }
        }

        return false;
    }
};
