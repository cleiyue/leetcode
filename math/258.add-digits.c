/*
 * @lc app=leetcode id=258 lang=c
 *
 * [258] Add Digits
 */

// @lc code=start

int addDigits(int num) {
    if (num < 10) return num;
    int count = 0;
    while (num > 0) {
        count += num % 10;
        num /= 10;
    }
    return addDigits(count);
}
// @lc code=end
