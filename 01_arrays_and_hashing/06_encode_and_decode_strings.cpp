/*
Problem: Encode and Decode Strings

Approach:
- Encode: Prefix each string with its length followed by '#'
- Decode: Parse length, skip '#', extract string of that length

Complexity:
- Time: O(n) for both encode and decode
- Space: O(n) for the encoded string
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string encode(vector<string>& strs) {
        string encode = "";
        for(string s : strs) {
            encode += to_string(s.size()) + "#" + s;
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;
        int i = 0;
        while(i < s.size()) {
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            decode.push_back(s.substr(j + 1, len));
            i = j + 1 + len;
        }
        return decode;
    }
};
