/*
 * @lc app=leetcode id=26 lang=c
 *
 * [26] Remove Duplicates from Sorted Array
 */

int removeDuplicates(int *nums, int numsSize) {
    int i = numsSize == 0 ? 0 : 1;
    for (int j = 1; j < numsSize; j++)
        if (nums[j] != nums[j - 1])
            nums[i++] = nums[j];
    return i;
}
