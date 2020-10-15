/*
 * @lc app=leetcode id=872 lang=c
 *
 * [872] Leaf-Similar Trees
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void findLeaf(struct TreeNode* root, int* arr, int* idx) {
    if (root == NULL) return;
    if (root->left == NULL && root->right == NULL) {
        arr[(*idx)++] = root->val;
        return;
    }
    findLeaf(root->right, arr, idx);
    findLeaf(root->left, arr, idx);
}

bool leafSimilar(struct TreeNode* root1, struct TreeNode* root2) {
    int arr1[100] = {0};
    int idx1 = 0;
    int arr2[100] = {0};
    int idx2 = 0;
    findLeaf(root1, arr1, &idx1);
    findLeaf(root2, arr2, &idx2);
    if (idx1 != idx2) return false;
    for (int i = 0; i < idx1; i++) {
        if (arr1[i] != arr2[i]) {
            return false;
        }
    }
    return true;
}
