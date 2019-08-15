/*
 * @lc app=leetcode id=112 lang=c
 *
 * [112] Path Sum
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sumPath(struct TreeNode* root, int total, int sum, int* stat) {
    if (root == NULL) return;
    total += root->val;
    if (root->right == NULL && root->left == NULL) {
        if (total == sum && *stat == 0) {
            *stat = 1;
        }
        return;
    }
    sumPath(root->left, total, sum, stat);
    sumPath(root->right, total, sum, stat);
}

bool hasPathSum(struct TreeNode* root, int sum) {
    int stat = 0;
    sumPath(root, 0, sum, &stat);
    if (stat == 1) return true;
    return false;
}
