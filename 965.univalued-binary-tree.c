/*
 * @lc app=leetcode id=965 lang=c
 *
 * [965] Univalued Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isUnivalTree(struct TreeNode* root) {
    bool leftCorrect = root->left == NULL ||
                       (root->val == root->left->val && isUnivalTree(root->left));
    bool rightCorrect = root->right == NULL ||
                        (root->val == root->right->val && isUnivalTree(root->right));
    return leftCorrect && rightCorrect;
}
