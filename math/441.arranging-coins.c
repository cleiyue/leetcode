/*
 * @lc app=leetcode id=441 lang=c
 *
 * [441] Arranging Coins
 */

// @lc code=start

// k(k+1) /2 = n -> k = sqrt(2n+1/4) - 1/2
int arrangeCoins(int n) {
    return sqrt(2) * sqrt(n + 0.125) - 0.5;
}
// @lc code=end
