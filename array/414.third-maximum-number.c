/*
 * @lc app=leetcode id=414 lang=c
 *
 * [414] Third Maximum Number
 */

// @lc code=start

void swap(long* a, long* b) {
    long temp = *a;
    *a = *b;
    *b = temp;
}

int thirdMax(int* nums, int numsSize) {
    long max1, max2, max3;
    int i;
    for (max1 = max2 = max3 = LONG_MIN, i = 0; i < numsSize; i++) {
        if (max3 >= nums[i] || max1 == nums[i] || max2 == nums[i])
            continue;
        max3 = nums[i];
        if (max2 < max3)
            swap(&max2, &max3);
        if (max1 < max2)
            swap(&max1, &max2);
    }
    return max3 == LONG_MIN ? max1 : max3;
}
// @lc code=end
