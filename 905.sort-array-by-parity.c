/*
 * @lc app=leetcode id=905 lang=c
 *
 * [905] Sort Array By Parity
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
// 偶数在前，奇数在后
int *sortArrayByParity(int *A, int ASize, int *returnSize) {
    int *B = malloc(ASize * sizeof(int));
    int start = 0;
    int end = ASize - 1;
    for (int i = 0; i < ASize; i++) {
        if ((A[i] & 1) == 0) {
            B[start] = A[i];
            start++;
        } else {
            B[end] = A[i];
            end--;
        }
    }
    *returnSize = ASize;
    return B;
}
