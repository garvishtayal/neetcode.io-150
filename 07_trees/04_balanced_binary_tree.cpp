/*
Problem: Balanced Binary Tree

Definition:
- A binary tree is balanced if:
    For every node, the height difference between left and right subtrees is at most 1

Approach:
- Use DFS with height calculation
- Instead of computing height separately for each node:
    - Return height if subtree is balanced
    - Return -1 immediately if subtree is unbalanced
- This allows early termination (pruning)

Key Insight:
- Height calculation + balance check combined in one DFS
- -1 acts as a sentinel value indicating "unbalanced"

Complexity:
- Time: O(n), each node is visited once
- Space: O(h), recursion stack
    - h = height of tree
    - Worst case (skewed): O(n)
    - Best case (balanced): O(log n)
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
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }

private:
    int height(TreeNode* root) {
        if (!root) return 0;

        // check left subtree
        int left = height(root->left);
        if (left == -1) return -1;

        // check right subtree
        int right = height(root->right);
        if (right == -1) return -1;

        // current node balance check
        if (abs(left - right) > 1) return -1;

        // return height if balanced
        return 1 + max(left, right);
    }
};
