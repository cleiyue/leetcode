/*
 * @lc app=leetcode id=46 lang=c
 *
 * [46] Permutations
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int *copy(int *nums, int n) {
    int *arr = malloc(n * sizeof(int));
    memcpy(arr, nums, n * sizeof(int));
    return arr;
}

void backtrack(int **ans, int *nums, int n, int first, int *returnSize, int *returnColumnSizes) {
    if (n == first) {
        ans[*returnSize] = copy(nums, n);
        returnColumnSizes[*returnSize] = n;
        (*returnSize)++;
    }
    for (int i = first; i < n; i++) {
        swap(nums, first, i);
        backtrack(ans, nums, n, first + 1, returnSize, returnColumnSizes);
        swap(nums, first, i);
    }
}

int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes) {
    *returnSize = 0;
    int **ans = malloc(1000 * sizeof(int *));
    *returnColumnSizes = malloc(1000 * sizeof(int));
    backtrack(ans, nums, numsSize, 0, returnSize, *returnColumnSizes);
    return ans;
}
