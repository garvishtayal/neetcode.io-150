/*
Problem: Binary Tree Maximum Path Sum

Approach:
- Use DFS to compute maximum gain from each node
- Ignore negative gains by taking max with 0
- At each node, calculate path passing through it
- Track global maximum path sum

Complexity:
- Time: O(n), each node visited once
- Space: O(h), recursion stack where h is tree height
*/

#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
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
    int maxSum = INT_MIN;
    
    int dfs(TreeNode* root) {
        // base case
        if (!root) return 0;

        // max gain from left and right subtrees
        int leftGain = max(0, dfs(root->left));
        int rightGain = max(0, dfs(root->right));

        // path sum passing through current node
        int pathSum = root->val + leftGain + rightGain;

        // update global maximum
        maxSum = max(maxSum, pathSum);

        // return max gain to parent
        return root->val + max(leftGain, rightGain);
    }

    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxSum;
    }
};
