/*
 * @lc app=leetcode id=942 lang=c
 *
 * [942] DI String Match
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char* S, int* returnSize) {
    int len = strlen(S);
    int low = 0;
    int high = len;
    int* ans = malloc((len + 1) * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < len; i++) {
        if (S[i] == 'I') {
            ans[(*returnSize)++] = low++;
            if (i == len - 1) {
                ans[(*returnSize)++] = low++;
            }
        } else {
            ans[(*returnSize)++] = high--;
            if (i == len - 1) {
                ans[(*returnSize)++] = high--;
            }
        }
    }
    return ans;
}
