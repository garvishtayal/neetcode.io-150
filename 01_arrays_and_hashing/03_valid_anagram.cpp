/*
Problem: Valid Anagram

Approach:
- Count character frequencies in both strings using hash maps
- Compare if frequency maps are identical

Complexity:
- Time: O(n)
- Space: O(1) - limited character set
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> hashs;
        for(int i = 0; i < s.size(); i++) {
            hashs[s[i]]++;
        }

        unordered_map<char, int> hasht;
        for(int i = 0; i < t.size(); i++) {
            hasht[t[i]]++;
        }

        return hashs == hasht;
    }
};
