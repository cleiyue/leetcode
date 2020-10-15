/*
 * @lc app=leetcode id=31 lang=c
 *
 * [31] Next Permutation
 */

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void reverse(int *arr, int n, int start) {
    int i = start, j = n - 1;
    while (i < j) {
        swap(arr, i, j);
        i++;
        j--;
    }
}

void nextPermutation(int *nums, int numsSize) {
    int i = numsSize - 2;
    while (i >= 0 && nums[i + 1] <= nums[i]) {
        i--;
    }
    if (i >= 0) {
        int j = numsSize - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    //递减序列翻转
    reverse(nums, numsSize, i + 1);
}
