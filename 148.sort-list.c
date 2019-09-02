/*
 * @lc app=leetcode id=148 lang=c
 *
 * [148] Sort List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode* temp = malloc(sizeof(struct ListNode));
    struct ListNode* p = temp;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1 != NULL) p->next = l1;
    if (l2 != NULL) p->next = l2;
    return temp->next;
}

struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) return head;
    struct ListNode *prev = NULL, *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;
    struct ListNode* l1 = sortList(head);
    struct ListNode* l2 = sortList(slow);
    return merge(l1, l2);
}
