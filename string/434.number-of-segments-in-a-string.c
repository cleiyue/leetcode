/*
 * @lc app=leetcode id=434 lang=c
 *
 * [434] Number of Segments in a String
 */

// @lc code=start

int countSegments(char* s) {
    int cnt = 0, i, len = strlen(s);
    for (i = 0; i < len; i++) {
        // 计算 ' '[a-z] 的个数
        if ((i == 0 || s[i - 1] == ' ') && s[i] != ' ')
            cnt++;
    }
    return cnt;
}
// @lc code=end
