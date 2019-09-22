/*
 * @lc app=leetcode id=814 lang=c
 *
 * [814] Binary Tree Pruning
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void helper(struct TreeNode* root, struct TreeNode* pre) {
    if (!root) return;
    helper(root->left, root);
    helper(root->right, root);
    if (root->val == 0 && !root->left && !root->right) {
        if (pre->left == root) {
            pre->left = NULL;
        } else {
            pre->right = NULL;
        }
    }
}

struct TreeNode* pruneTree(struct TreeNode* root) {
    helper(root->left, root);
    helper(root->right, root);
    return root;
}
