/*
 * @lc app=leetcode id=912 lang=c
 *
 * [912] Sort an Array
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void swap(int* nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

int partition(int* nums, int left, int right) {
    int pivot = nums[left];
    swap(nums, left, right);
    int idx = left;
    for (int i = left; i < right; i++) {
        if (nums[i] < pivot) {
            swap(nums, idx, i);
            idx++;
        }
    }
    swap(nums, idx, right);
    return idx;
}

void quickSelect(int* nums, int left, int right) {
    if (left >= right) return;
    int pivot_idx = partition(nums, left, right);
    quickSelect(nums, left, pivot_idx - 1);
    quickSelect(nums, pivot_idx + 1, right);
}

int* sortArray(int* nums, int numsSize, int* returnSize) {
    quickSelect(nums, 0, numsSize - 1);
    *returnSize = numsSize;
    return nums;
}
