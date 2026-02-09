/*
Problem: Design Add and Search Words Data Structure

Approach:
- Use a Trie to store words character by character
- Insert words by creating nodes as needed
- For search, use DFS to handle wildcard '.' characters
- Explore all possible child paths when '.' is encountered

Complexity:
- Time: O(n) for insert, O(26^k) in worst case for search with k wildcards
- Space: O(n * 26) for trie nodes
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

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* it = root;
        int i = 0;

        // insert characters into trie
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
        return searchInNode(word, 0, root);
    }

    bool searchInNode(string word, int i, TrieNode* node) {
        // invalid path
        if (node == nullptr) return false;

        // reached end of word
        if (i == word.size()) return node->end;

        // normal character match
        if (word[i] != '.') {
            int idx = word[i] - 'a';
            return searchInNode(word, i + 1, node->next[idx]);
        } 
        // wildcard: try all possible children
        else {
            for (int j = 0; j < 26; j++) {
                if (searchInNode(word, i + 1, node->next[j])) {
                    return true;
                }
            }
        }
        return false;
    }
};
