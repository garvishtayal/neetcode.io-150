/*
Problem: Alien Dictionary

Approach:
- Collect all unique characters
- Build directed graph from first differing characters of adjacent words
- Handle invalid prefix case
- Perform DFS based topological sort with cycle detection

Complexity:
- Time: O(C + E)
- Space: O(C + E)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        // collect all unique characters
        set<char> allChars;
        for (auto& w : words) {
            for (char c : w)
                allChars.insert(c);
        }

        // building adj list
        unordered_map<char, vector<char>> adj;

        for (int i = 1; i < words.size(); i++) {
            string& w1 = words[i - 1];
            string& w2 = words[i];

            int limit = min(w1.size(), w2.size());
            bool foundDiff = false;

            for (int z = 0; z < limit; z++) {
                char prev = w1[z];
                char curr = w2[z];

                if (prev != curr) {
                    adj[prev].push_back(curr);
                    foundDiff = true;
                    break;
                }
            }

            // invalid prefix case
            if (!foundDiff && w1.size() > w2.size()) {
                return "";
            }
        }

        // topological sort with cycle detection
        unordered_map<char, int> state; // 0=unvisited,1=visiting,2=visited
        stack<char> st;

        for (char c : allChars) {
            if (state[c] == 0) {
                if (!dfs(c, adj, state, st))
                    return ""; // cycle detected
            }
        }

        // build result
        string result = "";
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }

        return result;
    }

    bool dfs(char node, unordered_map<char, vector<char>>& adj,
             unordered_map<char, int>& state, stack<char>& st) {
        
        state[node] = 1; // visiting

        for (char nei : adj[node]) {

            // cycle detection
            if (state[nei] == 1)
                return false;

            if (state[nei] == 0) {
                if (!dfs(nei, adj, state, st))
                    return false;
            }
        }

        state[node] = 2; // visited
        st.push(node);   // post-order push
        return true;
    }
};
