/*
 * @lc app=leetcode id=143 lang=c
 *
 * [143] Reorder List
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define IDX(i, n) (((i) % 2) ? (n) - ((i) / 2) - 1 : ((i) / 2))
void reorderList(struct ListNode *head) {
    int len = 0;
    struct ListNode *node = head;
    while (node) {
        len++;
        node = node->next;
    }
    if (len < 3) return;
    struct ListNode **nodes = (struct ListNode *)malloc(len * sizeof(struct ListNode *));
    int i = 0;
    while (head) {
        nodes[i++] = head;
        head = head->next;
    }
    if (len < 3) return;
    for (i = 0; i < len - 1; ++i)
        nodes[IDX(i, len)]->next = nodes[IDX(i + 1, len)];
    nodes[IDX(i, len)]->next = NULL;
}
