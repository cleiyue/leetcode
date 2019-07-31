/*
 * @lc app=leetcode id=645 lang=c
 *
 * [645] Set Mismatch
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int dup = -1;
    int missing = 1;
    int* arr = calloc(numsSize + 1, sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        arr[nums[i]]++;
    }
    for (int i = 1; i < numsSize + 1; i++) {
        if (arr[i] == 0) {
            missing = i;
        } else if (arr[i] == 2) {
            dup = i;
        }
    }
    *returnSize = 2;
    //can't return ans[2]
    int* ans = malloc(2 * sizeof(int));
    ans[0] = dup;
    ans[1] = missing;
    return ans;
}
