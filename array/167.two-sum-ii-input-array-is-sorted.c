/*
 * @lc app=leetcode id=167 lang=c
 *
 * [167] Two Sum II - Input array is sorted
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize) {
    //hashmap O(n)
    // 如果都是小于 target
    // 如果包含0
    // int left = 0;
    // int right = 0;
    //    while (true) {
    //        for (int i = left + 1; i < numbersSize; i++) {
    //            if (numbers[left] + numbers[i] == target) {
    //                right = i;
    //                break;
    //            } else if (numbers[left] + numbers[i] > target) {
    //                left++;
    //                break;
    //            }
    //            if (i == numbersSize - 1) {
    //                left++;
    //            }
    //        }
    //        if (right > 0) {
    //            break;
    //        }
    //    }
    int left = 0;
    int right = numbersSize - 1;
    while (true) {
        if (numbers[left] + numbers[right] > target) {
            right--;
        } else if (numbers[left] + numbers[right] == target) {
            break;
        } else {
            left++;
        }
    }
    *returnSize = 2;
    int *ans = malloc(2 * sizeof(int));
    ans[0] = left + 1;
    ans[1] = right + 1;
    return ans;
}
