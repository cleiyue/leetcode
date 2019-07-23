/*
 * @lc app=leetcode id=485 lang=c
 *
 * [485] Max Consecutive Ones
 */

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int total = 0;
    int temp = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            temp++;
        } else {
            if (temp > total) {
                total = temp;
            }
            temp = 0;
        }
    }
    if (temp > total) {
        return temp;
    }
    return total;
}
