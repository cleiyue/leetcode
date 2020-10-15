/*
 * @lc app=leetcode id=116 lang=c
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
    if (root == NULL) {
        return root;
    }
    struct Node* Q[5000];
    int left = 0, right = 0;
    Q[right++] = root;
    while (left < right) {
        int size = right - left;
        for (int i = 0; i < size; i++) {
            struct Node* node = Q[left++];
            // 连接下一个节点
            if (i < size - 1) {
                node->next = Q[left];
            }
            // 下一层
            if (node->left != NULL) {
                Q[right++] = node->left;
            }
            if (node->right != NULL) {
                Q[right++] = node->right;
            }
        }
    }
    return root;
}
// @lc code=end
