/*
 * @lc app=leetcode id=278 lang=c
 *
 * [278] First Bad Version
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    int ans = 0, l = 1, r = n;
    while (l < r) {
        int mid = r / 2 + l / 2;  // 超出int范围
        if (isBadVersion(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
// @lc code=end
