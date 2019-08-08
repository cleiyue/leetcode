/*
 * @lc app=leetcode id=94 lang=c
 *
 * [94] Binary Tree Inorder Traversal
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
void traversal(struct TreeNode* root, int* ans, int* idx) {
    if (!root) return;
    traversal(root->left, ans, idx);
    ans[(*idx)++] = root->val;
    traversal(root->right, ans, idx);
}

//Recursive
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* ans = malloc(100 * sizeof(int));
    traversal(root, ans, returnSize);
    return ans;
}

//Morris Traversal
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = malloc(100 * sizeof(int));
    *returnSize = 0;
    struct TreeNode* curr = root;
    struct TreeNode* pre;
    while (curr != NULL) {
        if (curr->left == NULL) {
            ans[(*returnSize)++] = curr->val;
            curr = curr->right;
        } else {
            pre = curr->left;  // 找到左子树的最右节点
            while (pre->right != NULL) {
                pre = pre->right;
            }
            pre->right = curr;  // 最右节点指向root节点
            struct TreeNode* temp = curr;
            curr = curr->left;
            temp->left = NULL;
        }
    }
    return ans;
}
