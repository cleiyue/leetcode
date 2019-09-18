/*
 * @lc app=leetcode id=572 lang=c
 *
 * [572] Subtree of Another Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool helper(struct TreeNode* s, struct TreeNode* t) {
    if (!s && !t) return true;
    if (!s || !t) return false;
    if (s->val == t->val) {
        return helper(s->right, t->right) && helper(s->left, t->left);
    }
    return false;
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t) {
    if (!s) return false;
    return helper(s, t) || isSubtree(s->right, t) || isSubtree(s->left, t);
}
