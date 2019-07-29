/*
 * @lc app=leetcode id=136 lang=c
 *
 * [136] Single Number
 */

int singleNumber(int* nums, int numsSize) {
    int ans = 0;
    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }
    return ans;
}
