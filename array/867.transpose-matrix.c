/*
 * @lc app=leetcode id=867 lang=c
 *
 * [867] Transpose Matrix
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **transpose(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes) {
    int **B = malloc((*AColSize) * sizeof(int *));
    *returnColumnSizes = malloc((*AColSize) * sizeof(int));
    for (int j = 0; j < *AColSize; j++) {
        //指针还是不熟悉
        (*returnColumnSizes)[j] = ASize;
        int *row = malloc(ASize * sizeof(int));
        for (int i = 0; i < ASize; i++) {
            int *_row = A[i];
            row[i] = _row[j];
        }
        B[j] = row;
    }
    *returnSize = *AColSize;
    return B;
}
