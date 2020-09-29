/*
 * @lc app=leetcode id=326 lang=c
 *
 * [326] Power of Three
 */

// @lc code=start

bool isPowerOfThree(int n) {
    if (n == 0) return false;
    if (n == 1) return true;
    if (n % 3 == 0) {
        return isPowerOfThree(n / 3);
    } else {
        return false;
    }
}
// @lc code=end
