/*
 * @lc app=leetcode id=513 lang=c
 *
 * [513] Find Bottom Left Tree Value
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findAns(struct TreeNode *root, int *curDepth, int *res, int maxDepth) {
    if (maxDepth > *curDepth) {
        *curDepth = maxDepth;
        *res = root->val;
    }
    if (root->left)
        findAns(root->left, curDepth, res, maxDepth + 1);
    if (root->right)
        findAns(root->right, curDepth, res, maxDepth + 1);
}

int findBottomLeftValue(struct TreeNode *root) {
    int curDepth = -1, res = 0;
    findAns(root, &curDepth, &res, 0);
    return res;
}
