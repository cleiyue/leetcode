/*
 * @lc app=leetcode id=203 lang=c
 *
 * [203] Remove Linked List Elements
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeElements(struct ListNode* head, int val) {
    if (head == NULL)
        return head;
    if (head->val == val) {
        return removeElements(head->next, val);
    } else {
        head->next = removeElements(head->next, val);
        return head;
    }
}
