/*
 * @lc app=leetcode id=118 lang=c
 *
 * [118] Pascal's Triangle
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    int** ans = malloc(numRows * sizeof(int*));
    *returnColumnSizes = malloc(numRows * sizeof(int));
    for (int i = 1; i <= numRows; i++) {
        int* row = malloc(i * sizeof(int));
        (*returnColumnSizes)[i-1] = i;
        ans[i - 1] = row;
        row[0] = 1;
        row[i - 1] = 1;
        if (i - 2 > 0) {
            for (int j = 1; j < i - 1; j++) {
                row[j] = ans[i - 2][j - 1] + ans[i - 2][j];
            }
        }
    }
    return ans;
}
