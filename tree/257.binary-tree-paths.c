/*
 * @lc app=leetcode id=257 lang=c
 *
 * [257] Binary Tree Paths
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

void strJoin(char *str, int *idx, int t) {
    if (t < 0) {
        str[(*idx)++] = '-';
    }
    int k = abs(t);
    int *arr = malloc(100 * sizeof(int));
    int i = 0;
    while (k > 0) {
        arr[i++] = k % 10;
        k = k / 10;
    }
    while (i-- >= 1) {
        str[(*idx)++] = arr[i] + '0';
    }
}

void fillAns(struct TreeNode *root, char *str, int idx, char **ans, int *returnSize) {
    if (root == NULL) return;
    if (idx != 0) {
        str[idx++] = '-';
        str[idx++] = '>';
    }
    strJoin(str, &idx, root->val);
    if (root->left == NULL && root->right == NULL) {
        str[idx++] = '\0';
        ans[(*returnSize)++] = str;
        return;
    }
    char *strLeft = malloc(100 * sizeof(char));
    char *strRight = malloc(100 * sizeof(char));
    for (int i = 0; i < idx; i++) {
        strLeft[i] = str[i];
        strRight[i] = str[i];
    }
    fillAns(root->left, strLeft, idx, ans, returnSize);
    fillAns(root->right, strRight, idx, ans, returnSize);
}

char **binaryTreePaths(struct TreeNode *root, int *returnSize) {
    char **ans = malloc(100 * sizeof(char *));
    *returnSize = 0;
    char *str = malloc(100 * sizeof(char));
    fillAns(root, str, 0, ans, returnSize);
    return ans;
}
