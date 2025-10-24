/*
Problem: Group Anagrams

Approach:
- Build a signature for each string (character count or sorted string) and use it as a key in a hashmap to group anagrams.

Complexity:
- Time: O(n * m log m) if sorting each word, or O(n * m) using a count signature (n = number of strings, m = avg length).
- Space: O(n * m)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;
        for (auto &s : strs) {
            array<int, 26> cnt{};
            for (char c : s) cnt[c - 'a']++;
            string key;
            key.reserve(26 * 3);
            for (int c : cnt) key += to_string(c) + '#';
            groups[key].push_back(s);
        }
        vector<vector<string>> result;
        result.reserve(groups.size());
        for (auto &entry : groups) result.push_back(move(entry.second));
        return result;
    }
};
