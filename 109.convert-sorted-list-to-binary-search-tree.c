/*
 * @lc app=leetcode id=109 lang=c
 *
 * [109] Convert Sorted List to Binary Search Tree
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* convert(int* nums, int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = nums[mid];
    node->left = convert(nums, start, mid - 1);
    node->right = convert(nums, mid + 1, end);
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    int* arr = malloc(100000 * sizeof(int));
    int i = 0;
    while (head != NULL) {
        arr[i++] = head->val;
        head = head->next;
    }
    return convert(arr, 0, i - 1);
}
