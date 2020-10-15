/*
 * @lc app=leetcode id=119 lang=c
 *
 * [119] Pascal's Triangle II
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    if (rowIndex < 0)
        return NULL;
    *returnSize = rowIndex + 1;
    int* res = (int*)malloc(*returnSize * sizeof(int));
    for (int row = 0; row <= rowIndex; row++)
        for (int col = row; col >= 0; col--)
            res[col] = (col == 0 || col == row) ? 1 : res[col] + res[col - 1];
    return res;
}
