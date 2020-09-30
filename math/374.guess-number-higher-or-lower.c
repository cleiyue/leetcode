/*
 * @lc app=leetcode id=374 lang=c
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n) {
    if (n == 1) return 1;
    int l = 0, r = n;
    while (l < r) {
        int mid = r / 2 + l / 2;  // 分开计算，否则会超出int范围
        if (guess(mid) == -1) {
            r = mid;
        } else if (guess(mid) == 1) {
            l = mid + 1;
        } else {
            return mid;
        }
    }
    return r;
}
// @lc code=end
