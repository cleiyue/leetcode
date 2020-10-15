/*
 * @lc app=leetcode id=229 lang=c
 *
 * [229] Majority Element II
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *majorityElement(int *nums, int numsSize, int *returnSize) {
    int k1, k2, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == k1) {
            cnt1++;
        } else if (nums[i] == k2) {
            cnt2++;
        } else if (cnt1 == 0) {
            k1 = nums[i];
            cnt1++;
        } else if (cnt2 == 0) {
            k2 = nums[i];
            cnt2++;
        } else {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == k1) {
            cnt1++;
        }
        if (nums[i] == k2) {
            cnt2++;
        }
    }
    *returnSize = 0;
    int *ans = malloc(2 * sizeof(int));
    if (cnt1 > numsSize / 3) {
        ans[(*returnSize)++] = k1;
    }
    if (cnt2 > numsSize / 3) {
        ans[(*returnSize)++] = k2;
    }
    return ans;
}
