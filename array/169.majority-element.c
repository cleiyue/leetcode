/*
 * @lc app=leetcode id=169 lang=c
 *
 * [169] Majority Element
 */

int majorityElement(int *nums, int numsSize) {
    int k, count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            k = nums[i];
        }
        if (nums[i] == k) {
            count++;
        } else {
            count--;
        }
    }
    return k;
}
