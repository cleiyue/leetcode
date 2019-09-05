/*
 * @lc app=leetcode id=16 lang=c
 *
 * [16] 3Sum Closest
 */

#define ABS(a) ((a) > 0 ? (a) : -(a))

int cmp(const void* a, const void* b) {
    int A = *((int*)a);
    int B = *((int*)b);
    if (A == B)
        return 0;
    else if (A < B)
        return -1;
    else
        return 1;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int b, c, diff, minDiff = INT_MAX;
    for (int i = 0; i < numsSize; i++) {
        b = i + 1;
        c = numsSize - 1;
        while (b < c) {
            int diff = nums[i] + nums[b] + nums[c] - target;
            if (diff == 0) return target;
            if (ABS(diff) < ABS(minDiff)) {
                minDiff = diff;
            }
            if (diff > 0) {
                c--;
            } else {
                b++;
            }
        }
    }
    return target + minDiff;
}
