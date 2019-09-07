/*
 * @lc app=leetcode id=15 lang=c
 *
 * [15] 3Sum
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int max = numsSize * (numsSize - 1);
    int** ans = malloc(sizeof(int*) * max);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * max);
    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        int mid = i + 1;
        int high = numsSize - 1;
        while (mid < high) {
            int temp = nums[i] + nums[mid] + nums[high];
            if (temp == 0) {
                int* row = malloc(3 * sizeof(int));
                row[0] = nums[i];
                row[1] = nums[mid];
                row[2] = nums[high];
                ans[*returnSize] = row;
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                mid++;
                high--;
                while (mid < numsSize && nums[mid - 1] == nums[mid]) {
                    mid++;
                }
                while (high >= 0 && nums[high + 1] == nums[high]) {
                    high--;
                }
            } else if (temp > 0) {
                high--;
            } else {
                mid++;
            }
        }
    }
    return ans;
}
