/*
 * @lc app=leetcode id=1026 lang=c
 *
 * [1026] Maximum Difference Between Node and Ancestor
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void traverse(int rootVal, struct TreeNode* child, int* max) {
    if (!child) return;
    if (abs(rootVal - child->val) > *max) {
        *max = abs(rootVal - child->val);
    }
    traverse(rootVal, child->left, max);
    traverse(rootVal, child->right, max);
}

void helper(struct TreeNode* root, int* max) {
    if (!root) return;
    traverse(root->val, root->right, max);
    traverse(root->val, root->left, max);
    helper(root->right, max);
    helper(root->left, max);
}

int maxAncestorDiff(struct TreeNode* root) {
    int max = -1;
    helper(root, &max);
    return max;
}
