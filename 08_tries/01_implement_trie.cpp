/*
Problem: Implement Trie (Prefix Tree)

Approach:
- Use a TrieNode structure with an array of 26 pointers
- Insert words character by character into the trie
- Mark the end of a word using a boolean flag
- Traverse the trie to search words or prefixes

Complexity:
- Time: O(n), where n is the length of the word/prefix
- Space: O(n * 26) in worst case for trie nodes
*/

#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* next[26];
    bool end;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            next[i] = nullptr;
        }
        end = false;
    }
};

class PrefixTree {
    TrieNode* root;

public:
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* it = root;
        int i = 0;

        // traverse and create nodes as needed
        while (i < word.size()) {
            int idx = word[i] - 'a';

            if (it->next[idx] == NULL) {
                it->next[idx] = new TrieNode();
            }

            it = it->next[idx];
            i++;
        }

        // mark end of word
        it->end = true;
    }
    
    bool search(string word) {
        TrieNode* it = root;
        int i = 0;

        // traverse the trie
        while (i < word.size()) {
            int idx = word[i] - 'a';

            if (it->next[idx] == NULL) {
                return false;
            }

            it = it->next[idx];
            i++;
        }

        // word exists only if end flag is true
        return it->end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* it = root;
        int i = 0;

        // check prefix existence
        while (i < prefix.size()) {
            int idx = prefix[i] - 'a';

            if (it->next[idx] == NULL) {
                return false;
            }

            it = it->next[idx];
            i++;
        }

        return true;   
    }
};
