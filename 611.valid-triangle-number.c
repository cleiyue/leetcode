/*
 * @lc app=leetcode id=611 lang=c
 *
 * [611] Valid Triangle Number
 */

int cmp(const void* a, const void* b) {
    return *((int*)b) - *((int*)a);
}

int triangleNumber(int* nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), cmp);
    int ans = 0;
    for (int i = 0; i < numsSize - 2; i++) {
        int start = i + 1;
        int end = numsSize - 1;
        while (start < end) {
            if (nums[start] + nums[end] > nums[i]) {
                ans += end - start;
                start++;
            } else {
                end--;
            }
        }
    }
    return ans;
}
