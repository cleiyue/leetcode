/*
 * @lc app=leetcode id=653 lang=c
 *
 * [653] Two Sum IV - Input is a BST
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool findValue(struct TreeNode* root, struct TreeNode* head, int k) {
    if (!head) return false;
    if (head->val == k && head != root) {
        return true;
    } else if (k > head->val) {
        return findValue(root, head->right, k);
    } else {
        return findValue(root, head->left, k);
    }
}

bool helper(struct TreeNode* root, struct TreeNode* head, int k) {
    if (!root) return false;
    return findValue(root, head, k - root->val) || helper(root->left, head, k) || helper(root->right, head, k);
}

bool findTarget(struct TreeNode* root, int k) {
    struct TreeNode* head = root;
    return helper(root, head, k);
}
