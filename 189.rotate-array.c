/*
 * @lc app=leetcode id=189 lang=c
 *
 * [189] Rotate Array
 */

void rotate(int* nums, int numsSize, int k) {
    // 错误
    // k = k % numsSize;
    // if (k == 0) {
    //     return;
    // }
    // int i = 0;
    // int temp = nums[i];
    // int f = numsSize;
    // while (f-- > 0) { //[1,2,3,4] 1  [1,2,3,4,5,6] 2
    //     int next = (i + k) % numsSize;
    //     int j = nums[next];
    //     nums[next] = temp;
    //     i = next;
    //     temp = j;
    // }

    //两次循环
    // k = k % numsSize;
    // for (int i = 0; i < k; i++) {
    //     int k = nums[numsSize - 1];
    //     for (int j = numsSize - 2; j >= 0; j--) {
    //         nums[j + 1] = nums[j];
    //     }
    //     nums[0] = k;
    // }
    //
}
