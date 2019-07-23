/*
 * @lc app=leetcode id=985 lang=c
 *
 * [985] Sum of Even Numbers After Queries
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sumEvenAfterQueries(int *A, int ASize, int **queries, int queriesSize, int *queriesColSize, int *returnSize) {
    *returnSize = queriesSize;
    int *B = malloc(queriesSize * sizeof(int));
    //先计算偶数值，然后判断修改位的值奇偶，在判断增加位是奇偶，得出值
    int total = 0;
    for (int i = 0; i < ASize; i++) {
        if (A[i] % 2 == 0) {
            total += A[i];
        }
    }

    for (int i = 0; i < queriesSize; i++) {
        int a = A[queries[i][1]];
        A[queries[i][1]] += queries[i][0];
        if (a % 2 == 0) {
            if (queries[i][0] % 2 == 0) {
                total += queries[i][0];
            } else {
                total -= a;
            }
        } else if (queries[i][0] % 2 != 0) {
            total += A[queries[i][1]];
        }

        B[i] = total;
    }
    return B;
}
