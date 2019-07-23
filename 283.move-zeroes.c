/*
 * @lc app=leetcode id=283 lang=c
 *
 * [283] Move Zeroes
 */

void moveZeroes(int* nums, int numsSize) {
    int k = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[i - k] = nums[i];
        } else {
            k++;
        }
    }
    for (int i = 0; i < k; i++) {
        nums[numsSize - 1 - i] = 0;
    }
}
