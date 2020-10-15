/*
 * @lc app=leetcode id=21 lang=c
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* help(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL && l2 == NULL) return NULL;
    struct ListNode* ans = malloc(sizeof(struct ListNode));
    if (l1 == NULL) {
        ans->val = l2->val;
        ans->next = help(NULL, l2->next);
    } else if (l2 == NULL) {
        ans->val = l1->val;
        ans->next = help(l1->next, NULL);
    } else if (l1->val > l2->val) {
        ans->val = l2->val;
        ans->next = help(l1, l2->next);
    } else {
        ans->val = l1->val;
        ans->next = help(l1->next, l2);
    }
    return ans;
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    return help(l1, l2);
}
