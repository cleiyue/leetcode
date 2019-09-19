/*
 * @lc app=leetcode id=687 lang=c
 *
 * [687] Longest Univalue Path
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define MAX(a, b) (a > b ? a : b)

int getPath(struct TreeNode* root, int* ans) {
    if (!root) return 0;
    int left = getPath(root->left, ans);
    int right = getPath(root->right, ans);
    int arrowLeft = 0, arrowRight = 0;
    if (root->left && root->left->val == root->val) {
        arrowLeft += left + 1;
    }
    if (root->right && root->right->val == root->val) {
        arrowRight += right + 1;
    }
    *ans = MAX(*ans, arrowLeft + arrowRight);
    return MAX(arrowLeft, arrowRight);
}

int longestUnivaluePath(struct TreeNode* root) {
    int ans = 0;
    getPath(root, &ans);
    return ans;
}
