/*
 * @lc app=leetcode id=173 lang=c
 *
 * [173] Binary Search Tree Iterator
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct node {
    int* arr;
    int idx;
    int size;
} BSTIterator;

void helper(struct TreeNode* root, int *ans, int *size) {
    if(!root) return;
    helper(root->left, ans, size);
    ans[(*size)++] = root->val;
    helper(root->right, ans, size);
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator* obj = malloc(sizeof(BSTIterator));
    obj->arr = malloc(10000*sizeof(int));
    obj->idx = 0;
    obj->size = 0;
    helper(root, obj->arr, &(obj->size));
    return obj;
}

/** @return the next smallest number */
int bSTIteratorNext(BSTIterator* obj) {
    if(obj->idx < obj->size) {
        obj->idx++;
        return obj->arr[obj->idx - 1];
    }
    return -1;
}

/** @return whether we have a next smallest number */
bool bSTIteratorHasNext(BSTIterator* obj) {
  return obj->idx < obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/

