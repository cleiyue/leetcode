/*
 * @lc app=leetcode id=114 lang=c
 *
 * [114] Flatten Binary Tree to Linked List
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void flatten(struct TreeNode* root) {
    if (!root) return;
    flatten(root->left);
    flatten(root->right);
    if (root->left) {
        struct TreeNode* pre = root->left;
        while (pre->right) {
            pre = pre->right;
        }
        pre->right = root->right;
        root->right = root->left;
        root->left = NULL;
    }
}
