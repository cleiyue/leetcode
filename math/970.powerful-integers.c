/*
 * @lc app=leetcode id=970 lang=c
 *
 * [970] Powerful Integers
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* powerfulIntegers(int x, int y, int bound, int* returnSize) {
    int* arr = calloc(bound + 1, sizeof(int));
    for (int a = 1; a < bound; a *= x) {
        for (int b = 1; a + b <= bound; b *= y) {
            arr[a + b]++;
            if (y == 1) {
                break;
            }
        }
        if (x == 1) {
            break;
        }
    }
    *returnSize = 0;
    int* ans = malloc((bound + 1) * sizeof(int));
    for (int i = 0; i <= bound; i++) {
        if (arr[i] > 0) {
            ans[(*returnSize)++] = i;
        }
    }
    return ans;
}
