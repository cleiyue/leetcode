/*
 * @lc app=leetcode id=199 lang=c
 *
 * [199] Binary Tree Right Side View
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void findRight(struct TreeNode* root, int* ans, int* returnSize, int high) {
    if (!root) return;
    if (high >= *returnSize)
        if (root->right) {
            ans[(*returnSize)++] = root->right->val;
        } else if (root->left) {
            ans[(*returnSize)++] = root->left->val;
        }
    findRight(root->right, ans, returnSize, high + 1);
    findRight(root->left, ans, returnSize, high + 1);
}

int* rightSideView(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(50 * sizeof(int));
    *returnSize = 0;
    if (!root) return ans;
    ans[(*returnSize)++] = root->val;
    findRight(root, ans, returnSize, 1);
    return ans;
}
