/*
 * @lc app=leetcode id=53 lang=c
 *
 * [53] Maximum Subarray
 */

int maxSubArray(int* nums, int numsSize) {
    int totalCnt = nums[0];
    int tmpCnt = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if ((tmpCnt + nums[i]) < nums[i]) {
            tmpCnt = 0;
        }
        tmpCnt += nums[i];
        if (totalCnt < tmpCnt) {
            totalCnt = tmpCnt;
        }
    }
    return totalCnt;
}
