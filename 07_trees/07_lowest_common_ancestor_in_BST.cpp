/*
Problem: Lowest Common Ancestor of a Binary Search Tree

Definition:
- The lowest common ancestor (LCA) of two nodes p and q in a BST
  is the lowest node that has both p and q as descendants
  (a node can be a descendant of itself)

Approach:
- Leverage the Binary Search Tree property
- At each node:
    1) If both p and q values are smaller than current node value:
        - LCA lies in the left subtree
    2) If both p and q values are greater than current node value:
        - LCA lies in the right subtree
    3) Otherwise:
        - Current node is the split point and hence the LCA

Key Insight:
- BST ordering allows pruning half of the tree at each step
- First node where paths to p and q diverge is the answer

Complexity:
- Time: O(h), where h is the height of the BST
    - Worst case (skewed tree): O(n)
    - Best case (balanced tree): O(log n)
- Space: O(h), recursion stack
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // base case
        if (!root) return nullptr;

        // both nodes lie in left subtree
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);

        // both nodes lie in right subtree
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);

        // split point found
        return root;
    }
};