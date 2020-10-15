/*
 * @lc app=leetcode id=561 lang=c
 *
 * [561] Array Partition I
 */

int compare(int *a, int *b) {
    if (*a > *b)
        return 1;
    if (*a == *b)
        return 0;
    return -1;
}

int arrayPairSum(int *nums, int numsSize) {
    qsort(nums, numsSize, sizeof(int), compare);
    int i = 0;
    int result = 0;
    while (i < numsSize) {
        result += nums[i];
        i += 2;
    }
    return result;
}
