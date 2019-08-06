/*
 * @lc app=leetcode id=669 lang=c
 *
 * [669] Trim a Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* trimBST(struct TreeNode* root, int L, int R) {
    if (!root) return NULL;
    if (root->val >= L && root->val <= R) {
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
    } else if (root->val > R) {
        return trimBST(root->left, L, R);
    } else {
        return trimBST(root->right, L, R);
    }
    return root;
}
