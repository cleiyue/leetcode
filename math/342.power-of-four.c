/*
 * @lc app=leetcode id=342 lang=c
 *
 * [342] Power of Four
 */

// @lc code=start

bool isPowerOfFour(int num) {
    if (num == 0) return false;
    if (num == 1) return true;
    if (num % 4 == 0) {
        return isPowerOfFour(num / 4);
    } else {
        return false;
    }
}
// @lc code=end
