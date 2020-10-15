/*
 * @lc app=leetcode id=160 lang=c
 *
 * [160] Intersection of Two Linked Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#define NEXT(x) (x = x->next)
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    int lenA = 0, lenB = 0;
    for (struct ListNode* pA = headA; pA; NEXT(pA)) lenA++;
    for (struct ListNode* pB = headB; pB; NEXT(pB)) lenB++;
    for (int i = 0; i < (lenA - lenB); i++) NEXT(headA);
    for (int i = 0; i < (lenB - lenA); i++) NEXT(headB);
    while (headA != headB) {
        NEXT(headA);
        NEXT(headB);
    }
    return headA;
}
