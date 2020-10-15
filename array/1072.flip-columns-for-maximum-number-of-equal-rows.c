/*
 * @lc app=leetcode id=1072 lang=c
 *
 * [1072] Flip Columns For Maximum Number of Equal Rows
 */

int compare(int* a, int* b, int size) {
    for (int i = 0; i < size; i++) {
        if (a[0] == b[0]) {
            if (a[i] != b[i]) {
                return 0;
            }
        } else {
            if (a[i] == b[i]) {
                return 0;
            }
        }
    }
    return 1;
}

int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize) {
    int ans = 1;
    for (int i = 0; i < matrixSize; i++) {
        int cnt = 1;
        for (int j = i + 1; j < matrixSize; j++) {
            if (compare(matrix[i], matrix[j], *matrixColSize) == 1) {
                cnt++;
            }
        }
        if (cnt > ans) {
            ans = cnt;
        }
    }
    return ans;
}
