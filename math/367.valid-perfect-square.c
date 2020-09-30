/*
 * @lc app=leetcode id=367 lang=c
 *
 * [367] Valid Perfect Square
 */

// @lc code=start

bool isPerfectSquare(int num) {
    if (num == 1) return true;
    int l = 1, r = num / 2 + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        int temp = num / mid;
        if (mid > temp) {
            r = mid;  //这里不能 mid-1
        } else {
            if (mid == temp && num % mid == 0) return true;
            l = mid + 1;
        }
    }
    return false;
}
// @lc code=end
