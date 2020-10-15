/*
 * @lc app=leetcode id=106 lang=c
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildNode() {
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* buildTreeHelper(int* inorder, int* postorder, int* postIndex, int left, int right) {
    if (*postIndex < 0) return NULL;
    if (left > right) return NULL;
    struct TreeNode* node = buildNode();
    node->val = postorder[(*postIndex)--];
    int k = -1;
    for (int i = left; i <= right; i++) {
        if (inorder[i] == node->val) {
            k = i;
            break;
        }
    }
    if (k == -1) return NULL;
    node->right = buildTreeHelper(inorder, postorder, postIndex, k + 1, right);
    node->left = buildTreeHelper(inorder, postorder, postIndex, left, k - 1);
    return node;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorderSize == 0) return NULL;
    int postIndex = inorderSize - 1;
    return buildTreeHelper(inorder, postorder, &postIndex, 0, postIndex);
}
