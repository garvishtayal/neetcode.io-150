/*
Problem: Serialize and Deserialize Binary Tree

Approach:
- Use DFS (preorder) to serialize the tree
- Represent null nodes explicitly using a marker
- Concatenate values with a delimiter to form the string
- During deserialization, rebuild the tree using DFS with an index pointer

Complexity:
- Time: O(n), each node processed once
- Space: O(n), recursion stack and serialized string
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

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // use preorder traversal
        if (!root) {
            return "null_";
        }

        return to_string(root->val) + '_' +
               serialize(root->left) +
               serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int idx = 0;
        return dfsDeserialize(data, idx);
    }

    TreeNode* dfsDeserialize(string& data, int& idx) {
        string temp = "";

        // read until delimiter '_'
        for (int i = idx; i < data.size(); i++) {
            if (data[i] != '_') {
                temp += data[i];
            } else {
                idx = i + 1;
                break;
            }
        }

        // null node encountered
        if (temp == "null") {
            return nullptr;
        }

        // create node and build subtrees
        TreeNode* root = new TreeNode(stoi(temp));
        root->left = dfsDeserialize(data, idx);
        root->right = dfsDeserialize(data, idx);

        return root;
    }
};
