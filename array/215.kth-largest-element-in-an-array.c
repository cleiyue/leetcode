/*
 * @lc app=leetcode id=215 lang=c
 *
 * [215] Kth Largest Element in an Array
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

int quickSelect(int* nums, int left, int right, int smallKth) {
    if (left == right) return nums[left];
    int pivot_idx = partition(nums, left, right);
    if (pivot_idx == smallKth) {
        return nums[pivot_idx];
    } else if (pivot_idx > smallKth) {
        return quickSelect(nums, left, pivot_idx - 1, smallKth);
    } else {
        return quickSelect(nums, pivot_idx + 1, right, smallKth);
    }
}

int findKthLargest(int* nums, int numsSize, int k) {
    return quickSelect(nums, 0, numsSize - 1, numsSize - k);
}
