/*
 * @lc app=leetcode id=701 lang=c
 *
 * [701] Insert into a Binary Search Tree
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

struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root->val < val) {
        if (root->right == NULL) {
            root->right = createNode(val);
        } else {
            insertIntoBST(root->right, val);
        }

    } else if (root->val > val) {
        if (root->left == NULL) {
            root->left = createNode(val);
        } else {
            insertIntoBST(root->left, val);
        }
    }
    return root;
}
