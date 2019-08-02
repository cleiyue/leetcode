/*
 * @lc app=leetcode id=496 lang=c
 *
 * [496] Next Greater Element I
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = malloc(nums1Size * sizeof(int));
    *returnSize = 0;
    for (int i = 0; i < nums1Size; i++) {
        int index = 1000;
        for (int j = nums2Size - 1; j >= 0; j--) {
            if (nums1[i] == nums2[j]) {
                if (index < 1000) {
                    ans[(*returnSize)++] = nums2[index];
                } else {
                    ans[(*returnSize)++] = -1;
                }
                break;
            }
            if (nums1[i] < nums2[j]) {
                if (j < index) {
                    index = j;
                }
            }
        }
    }
    return ans;
}
