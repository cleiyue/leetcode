/*
 * @lc app=leetcode id=979 lang=c
 *
 * [979] Distribute Coins in Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int dfs(struct TreeNode* root, int* steps) {
    if (!root) return 0;
    int L = dfs(root->left, steps);
    int R = dfs(root->right, steps);
    *steps += abs(L) + abs(R);
    return root->val + L + R - 1;
}

int distributeCoins(struct TreeNode* root) {
    int steps = 0;
    dfs(root, &steps);
    return steps;
}
