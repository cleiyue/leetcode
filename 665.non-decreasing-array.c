/*
 * @lc app=leetcode id=665 lang=c
 *
 * [665] Non-decreasing Array
 */

bool checkPossibility(int *nums, int numsSize) {
    // 1.去掉一个数，看其它数是否递增
    //    int k = 0;
    //    if (numsSize < 3) {
    //        return true;
    //    }
    //    int a = nums[0]; //[3,4,2,3]
    //    for (int i = 1; i < numsSize; i++) {
    //        if (nums[i] < a) {
    //            k++;
    //        }
    //        a = nums[i];
    //    }
    //    if (k > 1) {
    //        return false;
    //    }
    //    return true;

    int k = 0;
    int j = 0;
    for (int i = 1; i < numsSize; i++) {  //[4,2,1]  [4,2,3]  [3,4,2,3]
        //凹的, [3,4,2,3] 只有一个凹，但是无法改成非递减
        if (nums[i] < nums[i - 1] && i <= numsSize - 2 && nums[i] < nums[i + 1]) {
            k++;
        }

        //凸的
        if (nums[i] > nums[i - 1] && i <= numsSize - 2 && nums[i] > nums[i + 1]) {
            j++;
        }
    }
    if (k == 0 && j == 0) {  //平滑的，可能递增也可能递减
        for (int i = 1; i < numsSize; i++) {
            if (nums[i] < nums[i - 1]) {  //递减
                return false;
            }
        }
    }

    if (k >= 2) {
        return false;
    }

    if (j >= 2) {
        return false;
    }
    return true;
}
