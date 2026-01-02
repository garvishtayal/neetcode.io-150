/*
Problem: Same Tree

Definition:
- Two binary trees are the same if they are structurally identical
  and have the same node values.

Approach:
- Use recursion (DFS)
- Base case:
    - If both nodes are NULL, return true
- If both nodes exist and values match:
    - Recursively check left subtrees
    - Recursively check right subtrees
- Otherwise, return false

Complexity:
- Time: O(n), where n is the number of nodes
- Space: O(h), recursion stack
    - h = height of tree
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) {
            return true;
        }
        if (p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) &&
                   isSameTree(p->right, q->right);
        } else {
            return false;
        }
    }
};
