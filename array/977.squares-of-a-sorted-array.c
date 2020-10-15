/*
 * @lc app=leetcode id=977 lang=c
 *
 * [977] Squares of a Sorted Array
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize) {
    *returnSize = ASize;
    int *B = malloc(ASize * sizeof(int));
    int i = 0;
    while (i + 1 < ASize && A[i] * A[i] >= A[i + 1] * A[i + 1]) {
        i++;
    }
    int j = i + 1;
    int k = 0;
    while (i >= 0 && j < ASize) {
        if (A[i] * A[i] <= A[j] * A[j]) {
            B[k] = A[i] * A[i];
            i--;
        } else {
            B[k] = A[j] * A[j];
            j++;
        }
        k++;
    }

    while (i >= 0) {
        B[k] = A[i] * A[i];
        i--;
        k++;
    }

    while (j < ASize) {
        B[k] = A[j] * A[j];
        j++;
        k++;
    }
    return B;
}
