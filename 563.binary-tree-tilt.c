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

int traverse(struct TreeNode* root, int* ans) {
    if (!root) return 0;
    int left = traverse(root->left, ans);
    int right = traverse(root->right, ans);
    *ans += ABS(left - right);
    return left + right + root->val;
}

int findTilt(struct TreeNode* root) {
    int ans = 0;
    traverse(root, &ans);
    return ans;
}
