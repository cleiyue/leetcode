/*
 * @lc app=leetcode id=448 lang=c
 *
 * [448] Find All Numbers Disappeared in an Array
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    for (int i = 0; i < numsSize; ++i)
        nums[abs(nums[i]) - 1] = abs(nums[abs(nums[i]) - 1]) * (-1);
    int length = 0;
    for (int i = 0; i < numsSize; ++i)
        if (nums[i] > 0) ++length;
    int* result = (int*)malloc(sizeof(int) * length);
    for (int i = 0, j = 0; i < numsSize; ++i)
        if (nums[i] > 0) result[j++] = i + 1;
    *returnSize = length;
    return result;
}
