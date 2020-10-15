/*
 * @lc app=leetcode id=1022 lang=c
 *
 * [1022] Sum of Root To Leaf Binary Numbers
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int sum) {
    if (root == NULL) return 0;
    sum = sum * 2 + root->val;
    return root->left == root->right ? sum : dfs(root->left, sum) + dfs(root->right, sum);
}

int sumRootToLeaf(struct TreeNode* root) {
    return dfs(root, 0);
}
