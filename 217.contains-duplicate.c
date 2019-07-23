/*
 * @lc app=leetcode id=217 lang=c
 *
 * [217] Contains Duplicate
 */

int compare(int *a, int *b) {
    if (*a > *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}

bool containsDuplicate(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    for (int i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}
