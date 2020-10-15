/*
 * @lc app=leetcode id=142 lang=c
 *
 * [142] Linked List Cycle II
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* detectCycle(struct ListNode* head) {
    if (head == NULL) return NULL;
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    struct ListNode* meet = NULL;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            meet = slow;
            break;
        }
    }
    if (meet == NULL) return NULL;
    struct ListNode* ans = head;
    while (meet != ans) {
        meet = meet->next;
        ans = ans->next;
    }
    return ans;
}
