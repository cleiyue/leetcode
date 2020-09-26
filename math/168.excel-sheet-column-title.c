/*
 * @lc app=leetcode id=168 lang=c
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start

char *convertToTitle(int n) {
    char *ret = (char *)malloc(sizeof(char) * 8);
    ret[7] = '\0';

    int i = 7;
    while (n) {
        n -= 1;
        ret[i - 1] = n % 26 + 'A';
        n /= 26;
        i--;
    }
    return ret + i;
}
// @lc code=end
