/*
 * @lc app=leetcode id=832 lang=c
 *
 * [832] Flipping an Image
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void reverseAndInvert(int *row, int size) {
    for (int i = 0; i < (size + 1) / 2; i++) {
        int left = row[i] ^ 1;
        row[i] = row[size - 1 - i] ^ 1;
        row[size - 1 - i] = left;
    }
}

int **flipAndInvertImage(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes) {
    for (int i = 0; i < ASize; i++) {
        reverseAndInvert(A[i], *AColSize);
    }
    // 这里之前的写法 returnSize = &ASize
    // returnColumnSizes = &AColSize 不知道为什么错误？
    *returnSize = ASize;
    *returnColumnSizes = AColSize;
    return A;
}
