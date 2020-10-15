/*
 * @lc app=leetcode id=349 lang=c
 *
 * [349] Intersection of Two Arrays
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//Brute Force
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

//Hash
#define HASHSIZE 1000

int MAX(int a, int b) {
    return a > b ? a : b;
}

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ret;
    int hash[HASHSIZE] = {0};

    if (!nums1 || !nums2)
        return NULL;

    *returnSize = 0;
    ret = malloc(MAX(nums1Size, nums2Size) * sizeof(int));

    for (int i = 0; i < nums1Size; ++i)
        hash[nums1[i]] = 1;

    for (int i = 0; i < nums2Size; ++i)
        if (hash[nums2[i]] == 1)
            hash[nums2[i]] = 2;

    for (int i = 0; i < HASHSIZE; ++i)
        if (hash[i] == 2)
            ret[(*returnSize)++] = i;

    return ret;
}
