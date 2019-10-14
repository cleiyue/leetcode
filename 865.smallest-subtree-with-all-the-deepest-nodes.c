/*
 * @lc app=leetcode id=865 lang=c
 *
 * [865] Smallest Subtree with all the Deepest Nodes
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Pair {
    int depth;
    struct TreeNode* node;
};

struct Pair* createPair(int depth, struct TreeNode* node) {
    struct Pair* pair = malloc(sizeof(struct Pair));
    pair->node = node;
    pair->depth = depth;
    return pair;
}

struct Pair* getDepth(struct TreeNode* root) {
    if (!root) return createPair(0, root);
    struct Pair* L = getDepth(root->left);
    struct Pair* R = getDepth(root->right);
    if (L->depth > R->depth) return createPair(L->depth + 1, L->node);
    if (L->depth < R->depth) return createPair(R->depth + 1, R->node);
    return createPair(L->depth + 1, root);
}

// 比较左右子树的高度
struct TreeNode* subtreeWithAllDeepest(struct TreeNode* root) {
    return getDepth(root)->node;
}
