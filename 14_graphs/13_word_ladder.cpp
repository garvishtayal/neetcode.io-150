/*
Problem: Word Ladder

Approach:
- Build an intermediate pattern graph using '*'
- Each word contributes L patterns (e.g., h*t, *it)
- Use BFS to find the shortest transformation sequence
- Each BFS level represents one transformation step

Complexity:
- Time: O(N * L^2), N = number of words, L = word length
- Space: O(N * L), adjacency map + BFS queue
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(string beginWord, string endWord,
            unordered_map<string, vector<string>>& adj) {

        queue<string> q;
        unordered_set<string> visited;

        q.push(beginWord);
        visited.insert(beginWord);
        int steps = 1;

        // BFS traversal
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string word = q.front();
                q.pop();

                // reached end word
                if (word == endWord)
                    return steps;

                // try all intermediate patterns
                for (int i = 0; i < word.size(); i++) {
                    string pattern = word;
                    pattern[i] = '*';

                    for (string &nei : adj[pattern]) {
                        if (!visited.count(nei)) {
                            visited.insert(nei);
                            q.push(nei);
                        }
                    }
                }
            }
            steps++;
        }
        return 0;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        // endWord must exist
        if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }

        int L = beginWord.size();
        wordList.push_back(beginWord);

        // build pattern graph
        unordered_map<string, vector<string>> adj;

        for (string &word : wordList) {
            for (int i = 0; i < L; i++) {
                string pattern = word;
                pattern[i] = '*';
                adj[pattern].push_back(word);
            }
        }

        // BFS to find shortest path
        return bfs(beginWord, endWord, adj);
    }
};
