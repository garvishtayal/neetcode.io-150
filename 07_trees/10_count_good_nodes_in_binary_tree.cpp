/*
Problem: Count Good Nodes in Binary Tree

Approach:
- Traverse the tree using DFS
- Maintain the maximum value seen so far on the path from root
- At each node:
    - If node value is greater than or equal to the current max,
      count it as a good node and update the max
- Recursively process left and right subtrees
- Sum the count from all paths

Why this works:
- Each node is evaluated only against values on its root-to-node path
- Passing max value avoids re-computation

Complexity:
- Time: O(n), each node is visited once
- Space: O(h), recursion stack (tree height)
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
private:
    // DFS helper to count good nodes
    int dfs(TreeNode* root, int currMax) {
        if (!root) return 0;

        int good = 0;
        if (root->val >= currMax) {
            good = 1;
            currMax = root->val;
        }

        return good +
               dfs(root->left, currMax) +
               dfs(root->right, currMax);
    }

public:
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val);
    }
};
