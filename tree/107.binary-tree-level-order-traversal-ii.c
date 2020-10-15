/*
 * @lc app=leetcode id=107 lang=c
 *
 * [107] Binary Tree Level Order Traversal II
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
        ans[(*returnSize)++] = malloc(1000 * sizeof(int));
    }
    help(root->left, level + 1, ans, returnSize, returnColumnSizes);
    help(root->right, level + 1, ans, returnSize, returnColumnSizes);
    ans[level - 1][returnColumnSizes[level - 1]++] = root->val;
}

void reverse(int** ans, int size, int* returnColumnSizes) {
    int i = 0, j = size - 1;
    while (i <= j) {
        int* temp = ans[i];
        ans[i] = ans[j];
        ans[j] = temp;
        int col = returnColumnSizes[i];
        returnColumnSizes[i] = returnColumnSizes[j];
        returnColumnSizes[j] = col;
        i++;
        j--;
    }
}

int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(1000 * sizeof(int*));
    *returnSize = 0;
    *returnColumnSizes = calloc(1000, sizeof(int));
    help(root, 1, ans, returnSize, *returnColumnSizes);
    reverse(ans, *returnSize, *returnColumnSizes);
    return ans;
}
