/*
 * @lc app=leetcode id=69 lang=c
 *
 * [69] Sqrt(x)
 */

// @lc code=start

int mySqrt(int x) {
    if (x == 0) return 0;
    int l = 1, r = x / 2;
    while (l < r) {
        int mid = (l + r) / 2 + 1;
        if (mid > x / mid) {
            r = mid - 1;
        } else if (mid < x / mid) {
            l = mid;
        } else {
            return mid;
        }
    }
    return l;
}
// @lc code=end
