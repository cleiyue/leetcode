/*
 * @lc app=leetcode id=922 lang=c
 *
 * [922] Sort Array By Parity II
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArrayByParityII(int *A, int ASize, int *returnSize) {
    *returnSize = ASize;
    int *B = malloc(ASize * sizeof(int));
    int even = 0, odd = 1;
    for (int i = 0; i < ASize; i++) {
        if ((A[i] & 1) == 0) {
            B[even] = A[i];
            even += 2;
        } else {
            B[odd] = A[i];
            odd += 2;
        }
    }
    return B;
}
