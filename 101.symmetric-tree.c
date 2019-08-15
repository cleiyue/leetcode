/*
 * @lc app=leetcode id=101 lang=c
 *
 * [101] Symmetric Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return true;
    if (root1 == NULL || root2 == NULL) return false;
    return (root1->val == root2->val) &&
           isMirror(root1->right, root2->left) &&
           isMirror(root1->left, root2->right);
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}
