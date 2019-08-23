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
void help(struct TreeNode* root, int level, int** ans, int* returnSize, int* returnColumnSizes) {
    if (root == NULL) return;
    if (level > *returnSize) {
        ans[*returnSize] = malloc(1000 * sizeof(int));
        (*returnSize)++;
    }
    ans[level - 1][returnColumnSizes[level - 1]++] = root->val;
    help(root->left, level + 1, ans, returnSize, returnColumnSizes);
    help(root->right, level + 1, ans, returnSize, returnColumnSizes);
}

double* averageOfLevels(struct TreeNode* root, int* returnSize) {
    int** ans = malloc(1000 * sizeof(int*));
    *returnSize = 0;
    int* returnColumnSizes = calloc(1000, sizeof(int));
    help(root, 1, ans, returnSize, returnColumnSizes);
    double* dans = malloc(*returnSize * sizeof(double));
    for (int i = 0; i < *returnSize; i++) {
        double total = 0;
        int colSize = returnColumnSizes[i];
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            total += ans[i][j];
        }
        if (colSize > 1) total = total / colSize;
        dans[i] = total;
    }
    return dans;
}
