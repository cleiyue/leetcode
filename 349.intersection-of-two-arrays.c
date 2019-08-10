/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = malloc(nums1Size * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] == nums2[j]) {
                if (*returnSize == 0) {
                    ans[(*returnSize)++] = nums1[i];
                    continue;
                }
                for (int k = 0; k < *returnSize; k++) {
                    if (ans[k] == nums1[i]) {
                        break;
                    } else if (k == *returnSize - 1) {
                        ans[(*returnSize)++] = nums1[i];
                        break;
                    }
                }
            }
        }
    }
    return ans;
}
