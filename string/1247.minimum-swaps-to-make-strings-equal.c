/*
 * @lc app=leetcode id=1247 lang=c
 *
 * [1247] Minimum Swaps to Make Strings Equal
 */

int minimumSwap(char* s1, char* s2) {
    int m = 0, n = 0;
    int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        if (s1[i] == s2[i]) {
            continue;
        } else if (s1[i] == 120) {
            m++;
        } else {
            n++;
        }
    }
    return (m + n) & 1 == 1 ? -1 : (m + 1) / 2 + (n + 1) / 2;
}
