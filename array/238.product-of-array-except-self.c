/*
 * @lc app=leetcode id=238 lang=c
 *
 * [238] Product of Array Except Self
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* ans = malloc(sizeof(int) * numsSize);
    int* ans1 = malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    ans[0] = 1;
    ans1[numsSize - 1] = 1;
    for (int i = 1; i < numsSize; i++) {
        ans[i] = ans[i - 1] * nums[i - 1];
        ans1[numsSize - 1 - i] = ans1[numsSize - i] * nums[numsSize - i];
    }
    for (int i = 0; i < numsSize; i++) {
        ans[i] *= ans1[i];
    }
    return ans;
}
