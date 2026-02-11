/*
Problem: Clone Graph

Approach:
- Use DFS with a hash map to clone the graph
- Map stores original node -> cloned node
- If a node is already cloned, return it directly
- For each node:
    - Create a copy
    - Recursively clone all neighbors
    - Attach cloned neighbors to the copy

Complexity:
- Time: O(V + E), where V is nodes and E is edges
- Space: O(V), for recursion stack and hash map
*/

#include <bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        // map original node -> cloned node
        map<Node*, Node*> oldToNew;
        return dfs(node, oldToNew);
    }

    Node* dfs(Node* node, map<Node*, Node*>& oldToNew) {
        // null check
        if (node == nullptr) {
            return nullptr;
        }

        // return already cloned node
        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        // create copy of current node
        Node* copy = new Node(node->val);
        oldToNew[node] = copy;

        // clone all neighbors
        for (Node* nei : node->neighbors) {
            copy->neighbors.push_back(dfs(nei, oldToNew));
        }

        return copy;
    }
};
