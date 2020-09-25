/*
 * @lc app=leetcode id=66 lang=c
 *
 * [66] Plus One
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    int *ans = malloc((digitsSize + 1) * sizeof(int));
    int k = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        int t = digits[i] + k;
        ans[i + 1] = t % 10;
        k = t / 10;
    }
    if (ans[1] == 0) {
        *returnSize = digitsSize + 1;
        ans[0] = 1;
        return ans;
    } else {
        *returnSize = digitsSize;
        return ans + 1;
    }
}
