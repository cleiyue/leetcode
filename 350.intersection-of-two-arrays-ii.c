/*
 * @lc app=leetcode id=350 lang=c
 *
 * [350] Intersection of Two Arrays II
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Runtime Error Message:
//Line 2: Char 14: runtime error: signed integer overflow: -2147483648 - 1 cannot be represented in type 'int' (solution.c)
int cmp(const int* a, const int* b) {
    if (*a == INT_MAX || *a == INT_MIN || *b == INT_MAX || *b == INT_MIN) {
        return ((double)*a - (double)*b) / 2;
    }
    return (*a - *b);
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = malloc(nums1Size * sizeof(int));
    *returnSize = 0;
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);
    int i = 0, j = 0;
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] > nums2[j]) {
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else {
            ans[(*returnSize)++] = nums1[i];
            i++;
            j++;
        }
    }
    return ans;
}
