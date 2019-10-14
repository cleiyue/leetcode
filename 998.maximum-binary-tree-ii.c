/*
 * @lc app=leetcode id=998 lang=c
 *
 * [998] Maximum Binary Tree II
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode(int val) {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* insertIntoMaxTree(struct TreeNode* root, int val) {
    if (!root) return createNode(val);
    if (root->val < val) {
        struct TreeNode* node = createNode(val);
        node->left = root;
        return node;
    } else {
        root->right = insertIntoMaxTree(root->right, val);
        return root;
    }
}
