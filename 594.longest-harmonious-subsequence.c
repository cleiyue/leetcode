/*
 * @lc app=leetcode id=594 lang=c
 *
 * [594] Longest Harmonious Subsequence
 */

int compare(int *a, int *b) {
    if (*a > *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}

int findLHS(int *nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    int ans = 0;
    qsort(nums, numsSize, sizeof(int), compare);
    int left = 0;
    int mid = 0;
    int A = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (A == nums[i] - 1 && mid == left) {
            mid = i;
        } else if (nums[i] - A > 1 || A - nums[i] > 1) {
            if (left != mid) {
                if (ans < i - left) {
                    ans = i - left;
                }
            }
            if (nums[i] - nums[i - 1] == 1) {
                left = mid;
                mid = i;
                A = nums[left];
            } else {
                left = mid = i;
                A = nums[left];
            }
        }
        if (i == numsSize - 1 && A == nums[i] - 1) {
            if (left != mid) {
                if (ans < i + 1 - left) {
                    ans = i + 1 - left;
                }
            }
        }
    }
    return ans;
}
