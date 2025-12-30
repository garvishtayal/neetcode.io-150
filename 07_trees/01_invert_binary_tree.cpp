/*
Problem: Invert Binary Tree

Approach:
- Use recursion (Depth-First Search)
- For each node:
    1) Swap its left and right children
    2) Recursively invert the left subtree
    3) Recursively invert the right subtree
- Base case: if node is NULL, return NULL

Why this works:
- Tree inversion is symmetric
- Each subtree is inverted independently

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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        // swap left and right children
        swap(root->left, root->right);

        // invert subtrees
        invertTree(root->left);
        invertTree(root->right);

        return root;
    }
};
