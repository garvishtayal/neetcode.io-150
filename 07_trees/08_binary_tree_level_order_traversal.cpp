/*
Problem: Binary Tree Level Order Traversal

Approach:
- Use Breadth-First Search (BFS) with a queue
- Start by pushing the root node into the queue
- While the queue is not empty:
    - Capture the current queue size to determine level boundary
    - Process exactly that many nodes to form one level
    - Push their children into the queue for the next level
- Append each level’s values to the result

Why this works:
- BFS naturally explores nodes level by level
- Queue size preserves separation between levels

Complexity:
- Time: O(n), each node is visited once
- Space: O(n), queue stores nodes level-wise
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // Empty tree
        if (!root) return {};

        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int sz = q.size();          // current level size
            vector<int> lvl;

            for (int i = 0; i < sz; i++) {
                TreeNode* curr = q.front(); q.pop();
                lvl.push_back(curr->val);

                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }

            res.push_back(lvl);         // store level
        }

        return res;
    }
};
