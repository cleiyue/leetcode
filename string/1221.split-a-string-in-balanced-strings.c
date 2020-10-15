/*
 * @lc app=leetcode id=1221 lang=c
 *
 * [1221] Split a String in Balanced Strings
 */

int balancedStringSplit(char* s) {
    int len = strlen(s);
    int ans = 0;
    int k = 0;
    while (--len >= 0) {
        if (s[len] == 'L') {
            k--;
        } else {
            k++;
        }
        if (k == 0) {
            ans++;
        }
    }
    return ans;
}
