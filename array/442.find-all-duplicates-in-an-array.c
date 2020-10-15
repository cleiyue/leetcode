/*
 * @lc app=leetcode id=442 lang=c
 *
 * [442] Find All Duplicates in an Array
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize) {
    int* ret = (int*)calloc(numsSize, sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        ret[nums[i] - 1]++;
    }
    for (int i = 0; i < numsSize; i++) {
        if (ret[i] > 1) {
            ret[(*returnSize)++] = i + 1;
        }
    }
    return ret;
}
