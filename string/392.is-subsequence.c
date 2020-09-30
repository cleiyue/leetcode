/*
 * @lc app=leetcode id=392 lang=c
 *
 * [392] Is Subsequence
 */

// @lc code=start

bool isSubsequence(char* s, char* t) {
    int n = strlen(s), m = strlen(t);
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }
    return i == n;
}
// @lc code=end
