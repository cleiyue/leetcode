/*
 * @lc app=leetcode id=821 lang=c
 *
 * [821] Shortest Distance to a Character
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 离后面的 C 最近也可以
int* shortestToChar(char* S, char C, int* returnSize) {
    int len = strlen(S);
    int* ans = malloc(len * sizeof(int));
    *returnSize = 0;
    int last_idx = -1;
    for (int i = 0; i < len; i++) {
        if (S[i] == C) {
            int j = *returnSize;
            while (j <= i) {
                ans[(*returnSize)++] = i - j;
                j++;
            }
            if (last_idx >= 0) {
                int k = (i - last_idx) / 2;
                for (int l = 1; l <= k; l++) {
                    ans[last_idx + l] = l;
                }
            }
            last_idx = i;
        }
    }
    int f = 1;
    while (*returnSize < len) {
        ans[(*returnSize)++] = f++;
    }
    return ans;
}
