/*
 * @lc app=leetcode id=198 lang=c
 *
 * [198] House Robber
 */

// @lc code=start

/*
* dp[i]=max(dp[i−2]+nums[i],dp[i−1])
* dp[0]=nums[0] 只有一间房屋，则偷窃该房屋
* dp[1]=max(nums[0],nums[1]) 只有两间房屋，选择其中金额较高的房屋进行偷窃
*/
#define max(a, b) (a > b ? a : b)

int rob(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    if (numsSize == 1) return nums[0];
    int first = nums[0];
    int second = max(nums[0], nums[1]);
    for (int i = 2; i < numsSize; i++) {
        int temp = second;
        second = max(first + nums[i], second);
        first = temp;
    }
    return second;
}
// @lc code=end
