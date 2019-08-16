/*
 * @lc app=leetcode id=83 lang=c
 *
 * [83] Remove Duplicates from Sorted List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) return NULL;
    if (head->next != NULL && head->val == head->next->val) {
        head->next = head->next->next;
        deleteDuplicates(head);
    } else if (head->next == NULL) {
        head->next = NULL;
    } else {
        deleteDuplicates(head->next);
    }
    return head;
}
