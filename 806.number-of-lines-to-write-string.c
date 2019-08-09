/*
 * @lc app=leetcode id=806 lang=c
 *
 * [806] Number of Lines To Write String
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numberOfLines(int* widths, int widthsSize, char* S, int* returnSize) {
    int* ans = calloc(2, sizeof(int));
    *returnSize = 2;
    int len = strlen(S);
    int total = 0;
    for (int i = 0; i < strlen(S); i++) {
        total += widths[S[i] - 'a'];
        if (total > 100) {
            total = widths[S[i] - 'a'];
            ans[0]++;
        }
    }
    ans[0]++;
    ans[1] = total;
    return ans;
}
