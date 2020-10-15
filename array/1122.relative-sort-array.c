/*
 * @lc app=leetcode id=1122 lang=c
 *
 * [1122] Relative Sort Array
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//ascending order. start 起始位置，end 结束位置
void sort(int *arr, int start, int end) {
    while (start < end) {
        for (int i = start; i <= end; i++) {
            if (arr[start] > arr[i]) {
                swap(arr, start, i);
            }
        }
        start++;
    }
}

int *relativeSortArray(int *arr1, int arr1Size, int *arr2, int arr2Size, int *returnSize) {
    *returnSize = arr1Size;
    int i = 0;
    for (int i2 = 0; i2 < arr2Size; i2++) {
        int item = arr2[i2];
        for (int j = i; j < arr1Size; j++) {
            if (arr1[j] == item) {
                swap(arr1, i, j);
                i++;
            }
        }
    }
    sort(arr1, i, arr1Size - 1);
    return arr1;
}
