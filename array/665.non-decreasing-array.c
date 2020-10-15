/*
 * @lc app=leetcode id=665 lang=c
 *
 * [665] Non-decreasing Array
 */

bool checkPossibility(int *nums, int numsSize) {
    int cnt = 0;
    for (int i = 1; i < numsSize && cnt <= 1; i++) {
        if (nums[i] < nums[i - 1]) {
            cnt++;
            if (i > 1 && nums[i] < nums[i - 2]) {
                nums[i] = nums[i - 1];
            }
        }
    }
    return cnt <= 1;
}
