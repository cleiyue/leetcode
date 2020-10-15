/*
 * @lc app=leetcode id=515 lang=c
 *
 * [515] Find Largest Value in Each Tree Row
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
#define MAX(a, b) (a > b ? a : b)
void help(struct TreeNode* root, int level, int* ans, int* returnSize) {
    if (root == NULL) return;
    if (level + 1 > *returnSize) {
        (*returnSize)++;
        ans[level] = -2147483648;
    }
    ans[level] = MAX(ans[level], root->val);
    help(root->left, level + 1, ans, returnSize);
    help(root->right, level + 1, ans, returnSize);
}

int* largestValues(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(1000 * sizeof(int));
    *returnSize = 0;
    help(root, 0, ans, returnSize);
    return ans;
}
