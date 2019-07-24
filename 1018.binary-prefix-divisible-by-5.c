/*
 * @lc app=leetcode id=1018 lang=c
 *
 * [1018] Binary Prefix Divisible By 5
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize) {
    bool* ans = malloc(ASize * sizeof(bool));
    *returnSize = ASize;
    int total = 0L;
    for (int i = 0; i < ASize; i++) {
        total = total << 1;
        total += A[i];
        if ((total = total % 5) == 0) {
            ans[i] = true;
        } else {
            ans[i] = false;
        }
    }
    return ans;
}
