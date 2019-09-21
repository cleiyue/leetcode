/*
 * @lc app=leetcode id=1008 lang=c
 *
 * [1008] Construct Binary Search Tree from Preorder Traversal
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

struct TreeNode* createNodeWithVal(int val) {
    struct TreeNode* node = createNode();
    node->val = val;
    return node;
}

void insert(struct TreeNode* root, int val) {
    if(val < root->val) {
        if(root->left == NULL) {
            root->left = createNodeWithVal(val);
        } else {
            insert(root->left, val);
        }
    } else {
        if(root->right == NULL) {
            root->right = createNodeWithVal(val);
        } else {
            insert(root->right, val);
        }
    }
}

struct TreeNode* bstFromPreorder(int* preorder, int preorderSize){
    struct TreeNode* root = createNode();
    root->val = preorder[0];
    if (preorderSize == 1) return root;
    for (int i = 1; i < preorderSize; i++) {
        insert(root, preorder[i]);
    }
    return root;
}



