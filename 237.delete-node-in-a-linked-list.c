/*
 * @lc app=leetcode id=237 lang=c
 *
 * [237] Delete Node in a Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void deleteNode(struct ListNode* node) {
    struct ListNode* next = node->next;
    node->val = next->val;
    node->next = next->next;
    free(next);
}
