/*
 * @lc app=leetcode id=171 lang=c
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start

int titleToNumber(char* s) {
    int len = strlen(s);
    int ans = 0;
    for (int i = 0; i < len; i++) {
        ans += (s[i] - 'A' + 1) * pow(26, len - i - 1);
    }
    return ans;
}
// @lc code=end
