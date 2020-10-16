#define MIN(a, b) (a > b ? b : a)

int** restoreMatrix(int* rowSum, int rowSumSize, int* colSum, int colSumSize, int* returnSize, int** returnColumnSizes) {
    int** ans = malloc(sizeof(int*) * rowSumSize);
    *returnColumnSizes = malloc(sizeof(int) * rowSumSize);
    for (int i = 0; i < rowSumSize; i++) {
        ans[i] = malloc(sizeof(int) * colSumSize);
        (*returnColumnSizes)[i] = colSumSize;
        for (int j = 0; j < colSumSize; j++) {
            ans[i][j] = MIN(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
        }
    }
    *returnSize = rowSumSize;
    return ans;
}
