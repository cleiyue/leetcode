/*
 * @lc app=leetcode id=61 lang=c
 *
 * [61] Rotate List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (k == 0) return head;
    if (head == NULL || head->next == NULL) return head;
    int len = 0;
    struct ListNode* temp = head;
    while (temp->next != NULL) {
        len++;
        temp = temp->next;
    }
    len++;
    temp->next = head;
    int t = k % len;
    struct ListNode* tail = head;
    t = len - t - 1;  //find tail
    while (t--) {
        tail = tail->next;
    }
    struct ListNode* newHead = tail->next;
    tail->next = NULL;
    return newHead;
}
