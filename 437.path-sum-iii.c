/*
 * @lc app=leetcode id=437 lang=c
 *
 * [437] Path Sum III
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void count(struct TreeNode* root, int sum, int* ans) {
    if (!root) return;
    sum -= root->val;
    if (sum == 0) {
        (*ans)++;
    }
    count(root->left, sum, ans);
    count(root->right, sum, ans);
}

void helper(struct TreeNode* root, int sum, int* ans) {
    if (!root) return;
    count(root, sum, ans);
    helper(root->left, sum, ans);
    helper(root->right, sum, ans);
}

int pathSum(struct TreeNode* root, int sum) {
    int ans = 0;
    helper(root, sum, &ans);
    return ans;
}
