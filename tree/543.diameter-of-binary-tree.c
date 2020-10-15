/*
 * @lc app=leetcode id=543 lang=c
 *
 * [543] Diameter of Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//一种经过根节点，一种不经过, 直径就是左节点高度+右节点高度
#define MAX(a, b) (a > b ? a : b)
int depth(struct TreeNode* root, int* ans) {
    if (root == NULL) return 0;
    int left = depth(root->left, ans);
    int right = depth(root->right, ans);
    *ans = MAX(*ans, left + right);
    return MAX(left, right) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) {
    if (!root) return 0;
    int ans = 0;
    depth(root, &ans);
    return ans;
}
