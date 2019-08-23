/*
 * @lc app=leetcode id=637 lang=c
 *
 * [637] Average of Levels in Binary Tree
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
void help(struct TreeNode* root, int level, double** ans, int* returnSize, int* returnColumnSizes) {
    if (root == NULL) return;
    if (level > *returnSize) {
        ans[*returnSize] = calloc(1000, sizeof(double));
        (*returnSize)++;
    }
    ans[level - 1][0] += root->val;
    returnColumnSizes[level - 1]++;
    help(root->left, level + 1, ans, returnSize, returnColumnSizes);
    help(root->right, level + 1, ans, returnSize, returnColumnSizes);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    double** ans = malloc(1000 * sizeof(double*));
    *returnSize = 0;
    int* returnColumnSizes = calloc(1000, sizeof(int));
    help(root, 1, ans, returnSize, returnColumnSizes);
    double* dans = malloc(*returnSize * sizeof(double));
    for (int i = 0; i < *returnSize; i++) {
        dans[i] = (double)ans[i][0] / returnColumnSizes[i];
    }
    return dans;
}
