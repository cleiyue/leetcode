/*
 * @lc app=leetcode id=268 lang=c
 *
 * [268] Missing Number
 */

int missingNumber(int *nums, int numsSize) {
    //这题比较奇怪
    int sum = numsSize * (numsSize + 1) / 2;
    for (int i = 0; i < numsSize; i++) {
        sum -= nums[i];
    }
    return sum;

    // 找到最大与最小的数，这些数是连续的
    // int min;
    // int max;
    // int total = 0;
    // for (int i = 0; i < numsSize; i++) {
    //     total += nums[i];
    //     if (i == 0) {
    //         min = nums[i];
    //         max = nums[i];
    //     } else {
    //         if (nums[i] > max) {
    //             max = nums[i];
    //         }

    //         if (nums[i] < min) {
    //             min = nums[i];
    //         }
    //     }
    // }
    // return max * (max + 1) / 2 - min * (min - 1) / 2 - total;
}
