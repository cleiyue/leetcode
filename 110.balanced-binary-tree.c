/*
 * @lc app=leetcode id=110 lang=c
 *
 * [110] Balanced Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;
    int r = maxDepth(root->right);
    int l = maxDepth(root->left);
    if (r > l) {
        return r + 1;
    }
    return l + 1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    if (abs(left - right) > 1) return false;
    bool r = isBalanced(root->right);
    bool l = isBalanced(root->left);
    return r && l;
}
