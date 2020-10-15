/*
 * @lc app=leetcode id=404 lang=c
 *
 * [404] Sum of Left Leaves
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumOfLeftLeaves(struct TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left != NULL && root->left->right == NULL && root->left->left == NULL) {
        return root->left->val + sumOfLeftLeaves(root->right);
    } else {
        return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
}
