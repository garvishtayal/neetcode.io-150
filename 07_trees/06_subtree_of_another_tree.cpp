/*
Problem: Subtree of Another Tree

Definition:
- A binary tree `subRoot` is a subtree of `root` if:
    - There exists a node in `root` such that the subtree rooted at that node
      is identical to `subRoot`

Approach:
- Traverse the main tree using DFS
- At each node in `root`:
    1) If current node value matches `subRoot` root value:
        - Call isSameTree to check full subtree match
    2) Otherwise:
        - Recursively check left subtree
        - Recursively check right subtree
- If any match is found, return true

Key Insight:
- Value match is used as a quick filter
- Full structure + value comparison is done only when values match

Complexity:
- Time: O(n * m) in worst case
    - n = number of nodes in `root`
    - m = number of nodes in `subRoot`
- Space: O(h), recursion stack
    - h = height of `root`
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // DFS traversal over main tree
        if (!root) return false;

        // Check subtree match when values align
        if (root->val == subRoot->val && isSameTree(root, subRoot))
            return true;

        // Continue searching left and right
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }

private:
    // Helper to check if two trees are identical
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q || p->val != q->val) return false;

        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};
