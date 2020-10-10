/*
 * @lc app=leetcode id=453 lang=c
 *
 * [453] Minimum Moves to Equal Array Elements
 */

// @lc code=start

int minMoves(int* nums, int numsSize) {
    int ans = 0;
    int min = nums[0];

    //找到最小值
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < min) min = nums[i];
    }

    // n-1 个元素 +1 相当于被选中的那个元素 -1
    for (int i = 0; i < numsSize; i++) {
        ans += abs(nums[i] - min);
    }
    return ans;
}

// @lc code=end
