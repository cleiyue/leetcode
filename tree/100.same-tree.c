/*
 * @lc app=leetcode id=100 lang=c
 *
 * [100] Same Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p != NULL && q != NULL && p->val != q->val) return false;
    if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
    if (!isSameTree(p->left, q->left) ||
        !isSameTree(p->right, q->right)) return false;
    return true;
}
