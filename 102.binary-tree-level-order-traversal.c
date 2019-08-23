/*
 * @lc app=leetcode id=102 lang=c
 *
 * [102] Binary Tree Level Order Traversal
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void help(struct TreeNode* root, int level, int** ans, int* returnSize, int* returnColumnSizes) {
    if (root == NULL) return;
    if (level > *returnSize) {
        ans[*returnSize] = malloc(1000 * sizeof(int));
        (*returnSize)++;
    }
    help(root->left, level + 1, ans, returnSize, returnColumnSizes);
    help(root->right, level + 1, ans, returnSize, returnColumnSizes);
    ans[level - 1][returnColumnSizes[level - 1]++] = root->val;
}

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(1000 * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = calloc(1000, sizeof(int));
    help(root, 1, ans, returnSize, *returnColumnSizes);
    return ans;
}
