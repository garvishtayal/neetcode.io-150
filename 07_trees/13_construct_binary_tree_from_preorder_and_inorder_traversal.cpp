/*
Problem: Construct Binary Tree from Preorder and Inorder Traversal

Approach:
- Preorder traversal gives the root of the current subtree first
- Inorder traversal determines how the tree splits into left and right subtrees
- Maintain an index in preorder to pick the next root
- For each root:
    - Locate it in inorder traversal
    - Elements to the left belong to the left subtree
    - Elements to the right belong to the right subtree
- Recursively build left and right subtrees

Why this works:
- Preorder fixes the root order
- Inorder fixes the subtree boundaries

Complexity:
- Time: O(n²) in worst case due to linear search in inorder
- Space: O(n), recursion stack and tree storage
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
    // Find root index in inorder range
    int search(vector<int>& inorder, int left, int right, int val) {
        for (int i = left; i <= right; i++) {
            if (inorder[i] == val)
                return i;
        }
        return -1;
    }

    // Recursive helper to build tree
    TreeNode* helper(
        vector<int>& preorder,
        vector<int>& inorder,
        int& preIdx,
        int left,
        int right
    ) {
        if (left > right) return nullptr;

        TreeNode* root = new TreeNode(preorder[preIdx++]);

        int inIdx = search(inorder, left, right, root->val);

        root->left  = helper(preorder, inorder, preIdx, left, inIdx - 1);
        root->right = helper(preorder, inorder, preIdx, inIdx + 1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return helper(preorder, inorder, preIdx, 0, inorder.size() - 1);
    }
};
