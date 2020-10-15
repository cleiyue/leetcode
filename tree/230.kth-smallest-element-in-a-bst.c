/*
 * @lc app=leetcode id=230 lang=c
 *
 * [230] Kth Smallest Element in a BST
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void inorder(struct TreeNode* root, int k, int* i, int* ans) {
    if (root == NULL) return;
    inorder(root->left, k, i, ans);
    if (k == ++(*i)) {
        *ans = root->val;
    }
    inorder(root->right, k, i, ans);
}

int kthSmallest(struct TreeNode* root, int k) {
    int ans = -1;
    int i = 0;
    inorder(root, k, &i, &ans);
    return ans;
}
