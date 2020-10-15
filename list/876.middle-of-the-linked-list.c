/*
 * @lc app=leetcode id=876 lang=c
 *
 * [876] Middle of the Linked List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* middleNode(struct ListNode* head) {
    int len = 0;
    struct ListNode* k = head;
    while (k != NULL) {
        len++;
        k = k->next;
    }
    k = head;
    for (int i = 0; i < len / 2; i++) {
        k = k->next;
    }
    return k;
}
