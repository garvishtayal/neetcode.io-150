/*
Problem: Maximum Depth of Binary Tree

Approach:
- Use recursion (Depth-First Search)
- For each node:
    1) Recursively compute depth of left subtree
    2) Recursively compute depth of right subtree
    3) Take the maximum of both and add 1 for current node
- Base case: if node is NULL, depth = 0

Key Insight:
- Height of a tree = 1 + max(height of left, height of right)
- Naturally fits recursive tree structure

Complexity:
- Time: O(n), where n is the number of nodes
- Space: O(h), due to recursion stack
    - h = height of the tree
    - Worst case (skewed tree): O(n)
    - Best case (balanced tree): O(log n)
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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;

        return 1 + max(
            maxDepth(root->left),
            maxDepth(root->right)
        );
    }
};
