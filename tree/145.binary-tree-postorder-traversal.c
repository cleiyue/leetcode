/*
 * @lc app=leetcode id=145 lang=c
 *
 * [145] Binary Tree Postorder Traversal
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

void traversal(struct TreeNode* root, int* ans, int* returnSize) {
    if (!root) return;
    traversal(root->left, ans, returnSize);
    traversal(root->right, ans, returnSize);
    ans[(*returnSize)++] = root->val;  //位置
}

//Recursive
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(100 * sizeof(int));
    *returnSize = 0;
    traversal(root, ans, returnSize);
    return ans;
}
