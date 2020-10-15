/*
 * @lc app=leetcode id=538 lang=c
 *
 * [538] Convert BST to Greater Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* dfs(struct TreeNode* root, int* total) {
    if (root == NULL) return NULL;
    dfs(root->right, total);
    root->val += *total;
    *total = root->val;
    dfs(root->left, total);
    return root;
}

struct TreeNode* convertBST(struct TreeNode* root) {
    int total = 0;
    return dfs(root, &total);
}
