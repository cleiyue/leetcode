/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void traversal(struct TreeNode* root, int* ans, int* idx) {
    if (!root) return;
    traversal(root->left, ans, idx);
    ans[(*idx)++] = root->val;
    traversal(root->right, ans, idx);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(100 * sizeof(int));
    traversal(root, ans, returnSize);
    return ans;
}
