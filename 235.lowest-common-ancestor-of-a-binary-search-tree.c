/*
 * @lc app=leetcode id=235 lang=c
 *
 * [235] Lowest Common Ancestor of a Binary Search Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(p->val > root->val && q->val > root->val) {
        return lowestCommonAncestor(root->right, p, q);
    } else if(p->val < root->val && q->val < root->val) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
}

