/*
Problem: Binary Tree Right Side View

Approach:
- Perform level order traversal (BFS) using a queue
- Process the tree level by level
- For each level:
    - Track the number of nodes using queue size
    - The last node processed at that level is visible from the right side
- Store that node’s value in the result

Why this works:
- BFS ensures nodes are processed in level order
- Selecting the last node per level captures the rightmost view

Complexity:
- Time: O(n), each node is visited once
- Space: O(n), queue holds nodes per level
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
    vector<int> rightSideView(TreeNode* root) {
        // Empty tree
        if (!root) return {};

        vector<int> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();      // nodes at current level

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front(); q.pop();

                if (i == sz - 1)    // rightmost node
                    res.push_back(curr->val);

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }

        return res;
    }
};
