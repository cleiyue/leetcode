/*
 * @lc app=leetcode id=2 lang=c
 *
 * [2] Add Two Numbers
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* result = malloc(sizeof(struct ListNode));
    struct ListNode* head = result;
    int carrybit = 0, sum = 0;
    while (l1 || l2) {
        if (!l1) {
            sum = (l2->val + carrybit);
            l2 = l2->next;
        } else if (!l2) {
            sum = (l1->val + carrybit);
            l1 = l1->next;
        } else {
            sum = (l1->val + l2->val + carrybit);
            l1 = l1->next;
            l2 = l2->next;
        }
        if (sum >= 10)
            carrybit = 1;
        else
            carrybit = 0;
        result->val = sum % 10;
        if ((l1 || l2)) {
            result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            result = result->next;
        }
    }
    if (carrybit) {
        result->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        result->next->val = 1;
        result->next->next = NULL;
    } else {
        result->next = NULL;
    }
    return head;
}
