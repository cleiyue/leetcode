/*
 * @lc app=leetcode id=219 lang=c
 *
 * [219] Contains Duplicate II
 */

#define abs(a, b) (a > b ? a - b : b - a)

bool containsNearbyDuplicate(int *nums, int numsSize, int k) {
    int *order = malloc(sizeof(int) * numsSize);
    int flag = 1;
    for (int i = 0; i < numsSize; i++) {
        order[i] = i;
    }
    while (flag) {
        flag = 0;
        for (int i = 0; i < numsSize - 1; i++) {
            if (nums[i] > nums[i + 1]) {  // 排序，递增
                //交换两个数
                nums[i] ^= nums[i + 1];
                nums[i + 1] ^= nums[i];
                nums[i] ^= nums[i + 1];
                //交换地址
                order[i] ^= order[i + 1];
                order[i + 1] ^= order[i];
                order[i] ^= order[i + 1];
                flag = 1;
            } else if (nums[i] == nums[i + 1] && abs(order[i], order[i + 1]) <= k) {
                return true;
            }
        }
    }
    return false;
}
