/*
Problem: Diameter of Binary Tree

Definition:
- Diameter = number of edges in the longest path between any two nodes
- Path does NOT need to pass through the root

Approach:
- Use DFS (postorder traversal)
- At each node:
    1) Compute height of left subtree
    2) Compute height of right subtree
    3) Diameter passing through this node = left + right
    4) Update global maximum diameter
- Return height of current subtree to parent

Key Insight:
- Height is returned upward (DP state)
- Diameter is updated globally while unwinding recursion

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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        dfs(root, res);
        return res;
    }

private:
    int dfs(TreeNode* root, int& res) {
        if (!root) return 0;

        // heights of left and right subtrees
        int left = dfs(root->left, res);
        int right = dfs(root->right, res);

        // update diameter using current node
        res = max(res, left + right);

        // return height of current subtree
        return 1 + max(left, right);
    }
};
