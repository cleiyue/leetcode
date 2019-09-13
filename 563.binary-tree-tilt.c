/*
 * @lc app=leetcode id=563 lang=c
 *
 * [563] Binary Tree Tilt
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define ABS(a) ((a) > 0 ? (a) : -(a))
int total(struct TreeNode* root) {
    if (!root) return 0;
    return root->val + total(root->left) + total(root->right);
}

int findTilt(struct TreeNode* root) {
    if (!root) return 0;
    if (root->left && root->right) {
        return ABS(total(root->left) - total(root->right)) + findTilt(root->left) + findTilt(root->right);
    } else if (root->left) {
        return ABS(total(root->left)) + findTilt(root->left);
    } else if (root->right) {
        return ABS(total(root->right)) + findTilt(root->right);
    } else {
        return 0;
    }
}
