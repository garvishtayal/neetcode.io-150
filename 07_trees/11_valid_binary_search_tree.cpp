/*
Problem: Validate Binary Search Tree

Approach:
- Use DFS to validate the BST property
- For every node, maintain a valid value range (min, max)
- Initially, the range is (-∞, +∞)
- At each node:
    - Its value must lie strictly between min and max
    - Left subtree gets updated max = current node value
    - Right subtree gets updated min = current node value
- If all nodes satisfy the constraint, the tree is a valid BST

Why this works:
- BST validity depends on global constraints, not just parent-child comparison
- Passing range ensures correctness across entire subtree

Complexity:
- Time: O(n), each node is visited once
- Space: O(h), recursion stack where h is tree height
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for a binary tree node.
 */
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
    // DFS with value range validation
    bool dfs(TreeNode* root, long minVal, long maxVal) {
        // Empty subtree is valid
        if (!root) return true;

        // Current node violates BST constraint
        if (root->val <= minVal || root->val >= maxVal)
            return false;

        // Validate left and right subtrees with updated ranges
        return dfs(root->left, minVal, root->val) &&
               dfs(root->right, root->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        // Start with full value range
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};
