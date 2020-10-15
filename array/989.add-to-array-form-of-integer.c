/*
 * @lc app=leetcode id=989 lang=c
 *
 * [989] Add to Array-Form of Integer
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* A, int ASize, int K, int* returnSize) {
    int len = ASize > 10 ? ASize + 1 : 11;
    int* res = malloc(len * sizeof(int));
    int i = ASize - 1, j = len - 1;
    for (; i >= 0; i--, j--) {
        K = A[i] + K;
        res[j] = K % 10;
        K /= 10;
    }
    for (; K > 0; K /= 10, j--) res[j] = K % 10;
    *returnSize = len - j - 1;
    return res + j + 1;
}
