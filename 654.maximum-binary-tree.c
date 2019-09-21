/*
 * @lc app=leetcode id=654 lang=c
 *
 * [654] Maximum Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createNode() {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct TreeNode* root, int k) {
    if (k > root->val) {
        struct TreeNode* node = createNode();
        node->val = root->val;
        node->right = root->right;
        node->left = root->left;
        root->val = k;
        root->left = node;
        root->right = NULL;
    } else if (k < root->val) {
        if (root->right == NULL) {
            struct TreeNode* node = createNode();
            node->val = k;
            root->right = node;
        } else {
            insert(root->right, k);
        }
    }
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    struct TreeNode* root = createNode();
    root->val = nums[0];
    if (numsSize == 1) return root;
    for (int i = 1; i < numsSize; i++) {
        insert(root, nums[i]);
    }
    return root;
}
