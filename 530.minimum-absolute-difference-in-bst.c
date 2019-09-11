/*
 * @lc app=leetcode id=530 lang=c
 *
 * [530] Minimum Absolute Difference in BST
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int rightLeft(struct TreeNode* root) {
    if (root->left) {
        return rightLeft(root->left);
    } else {
        return root->val;
    }
}

int leftRight(struct TreeNode* root) {
    if (root->right) {
        return leftRight(root->right);
    } else {
        return root->val;
    }
}

int getMinimumDifference(struct TreeNode* root) {
    int lDiff = INT_MAX, rDiff = INT_MAX;
    if (root->right != NULL) {
        rDiff = rightLeft(root->right) - root->val;
        int diff = getMinimumDifference(root->right);
        if (rDiff > diff) {
            rDiff = diff;
        }
    }
    if (root->left != NULL) {
        lDiff = root->val - leftRight(root->left);
        int diff = getMinimumDifference(root->left);
        if (lDiff > diff) {
            lDiff = diff;
        }
    }
    return lDiff < rDiff ? lDiff : rDiff;
}
