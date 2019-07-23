/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 */

void nextPermutation(int *nums, int numsSize) {
    // 如果是最大值，则返回最小值
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < nums[i - 1]) {
        }
    }

    //
}

//123 - 132 - 213 - 231 - 312 - 321
//1234 -- 1243 -- 1324 --1342

//321 - 123 - 132 - 213 - 231 - 312 - 321
