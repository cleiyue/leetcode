/*
 * @lc app=leetcode id=172 lang=c
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start

int trailingZeroes(int n) {
    int ans = 0;
    while (n >= 5) {
        ans += n / 5;
        n /= 5;
    }
    return ans;
}
// @lc code=end
