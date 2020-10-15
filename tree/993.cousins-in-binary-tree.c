/*
 * @lc app=leetcode id=993 lang=c
 *
 * [993] Cousins in Binary Tree
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct Map {
    int depth;
    struct TreeNode* root;
};

void parent(struct TreeNode* root, int x, int depth, struct Map* map) {
    if (root == NULL) return;
    depth++;
    if (root->left != NULL && root->left->val == x) {
        map->root = root;
        map->depth = depth;
        return;
    }
    if (root->right != NULL && root->right->val == x) {
        map->root = root;
        map->depth = depth;
        return;
    }
    parent(root->right, x, depth, map);
    parent(root->left, x, depth, map);
}

struct Map* create() {
    struct Map* map = malloc(sizeof(struct Map));
    map->depth = 0;
    map->root = NULL;
    return map;
}

bool isCousins(struct TreeNode* root, int x, int y) {
    struct Map* xMap = create();
    struct Map* yMap = create();
    parent(root, x, 0, xMap);
    parent(root, y, 0, yMap);
    return xMap->root != yMap->root && xMap->depth == yMap->depth;
}
