/*
 * @lc app=leetcode id=674 lang=c
 *
 * [674] Longest Continuous Increasing Subsequence
 */

int findLengthOfLCIS(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    if (numsSize == 1) {
        return 1;
    }
    int t = 1, k = 1;
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            t++;
        } else {
            if (t > k) {
                k = t;
            }
            t = 1;
        }
    }
    return k > t ? k : t;
}
