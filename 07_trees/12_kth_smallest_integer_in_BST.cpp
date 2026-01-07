/*
Problem: Kth Smallest Element in a BST

Approach:
- Use inorder traversal (DFS) on the BST
- Inorder traversal of a BST visits nodes in sorted order
- Maintain a counter to track how many nodes have been visited
- When the counter reaches k, store the current node value as the result
- Stop further traversal once the answer is found

Why this works:
- BST property guarantees inorder traversal yields sorted values
- Early stopping avoids unnecessary traversal

Complexity:
- Time: O(n) in worst case, O(h + k) with early stopping
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
private:
    int count = 0;
    int res = -1;

    // Inorder DFS to find kth smallest element
    void dfs(TreeNode* root, int k) {
        if (!root || count >= k) return;

        dfs(root->left, k);

        count++;
        if (count == k) {
            res = root->val;
            return;
        }

        dfs(root->right, k);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        dfs(root, k);
        return res;
    }
};
