/*
 * @lc app=leetcode id=35 lang=c
 *
 * [35] Search Insert Position
 */

int searchInsert(int* nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] >= target) {
            return i;
        }
    }
    return numsSize;
}
