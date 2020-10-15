/*
 * @lc app=leetcode id=888 lang=c
 *
 * [888] Fair Candy Swap
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int sum(int *arr, int size) {
    int sum = 0;
    while (size > 0) {
        sum += arr[size - 1];
        size--;
    }
    return sum;
}

int *fairCandySwap(int *A, int ASize, int *B, int BSize, int *returnSize) {
    int totalA = sum(A, ASize);
    int totalB = sum(B, BSize);
    int fair = (totalA + totalB) / 2;
    int s = totalA - fair;
    int *ans = malloc(2 * sizeof(int));
    for (int i = 0; i < ASize; i++) {
        if (A[i] < s) {
            continue;
        }
        for (int j = 0; j < BSize; j++) {
            if (B[j] == A[i] - s) {
                ans[0] = A[i];
                ans[1] = B[j];
                // 之前在这里直接return  ans 报错，因为没有设置 returnSize
                break;
            }
        }
    }
    *returnSize = 2;
    return ans;
}
