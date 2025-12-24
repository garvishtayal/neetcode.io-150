/*
Problem: LRU Cache

Approach:
- Use a combination of:
    - Doubly Linked List (DLL) to maintain usage order
    - Hash Map to provide O(1) access to nodes
- Most Recently Used (MRU) node is kept near the right sentinel
- Least Recently Used (LRU) node is kept near the left sentinel
- Operations:
    - get(key):
        - If key exists, move node to MRU position
        - Return value
    - put(key, value):
        - Insert/update node and move to MRU position
        - If capacity exceeds, remove LRU node

Design:
- `left` and `right` are dummy sentinel nodes
- `remove(node)` removes node from DLL
- `insert(node)` inserts node before `right` (MRU position)

Complexity:
- Time: O(1) for both get and put
- Space: O(capacity)
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
private:
    int cap;
    unordered_map<int, Node*> cache;
    Node* left;
    Node* right;

    // Remove node from doubly linked list
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    // Insert node at MRU position (before right sentinel)
    void insert(Node* node) {
        Node* prev = right->prev;
        prev->next = node;
        node->prev = prev;
        node->next = right;
        right->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        cache.clear();

        // Initialize dummy sentinel nodes
        left = new Node(0, 0);
        right = new Node(0, 0);
        left->next = right;
        right->prev = left;
    }

    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            insert(node);
            return node->val;
        }
        return -1;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }

        Node* newNode = new Node(key, value);
        cache[key] = newNode;
        insert(newNode);

        // Evict LRU if capacity exceeded
        if (cache.size() > cap) {
            Node* lru = left->next;
            remove(lru);
            cache.erase(lru->key);
            delete lru;
        }
    }
};
