/*
 * @lc app=leetcode id=5 lang=c
 *
 * [5] Longest Palindromic Substring
 */

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 2) return s;
    char* ans = malloc((len + 1) * sizeof(char));
    int j = 0, MAX = 0, start = 0, end = 0;
    for (int i = 0; i < len; i++) {
        if (MAX == len) break;
        int Ak = 0, Acnt = 0, Bk = 1, Bcnt = 1, a = 0;
        while (i >= Ak && i + 1 + Ak < len && s[i - Ak] == s[i + 1 + Ak]) {
            Ak++;
            Acnt += 2;
        }
        while (i >= Bk && i + Bk < len && s[i - Bk] == s[i + Bk]) {
            Bk++;
            Bcnt += 2;
        }
        if (Acnt < MAX && Bcnt < MAX) continue;
        if (Acnt > Bcnt) {
            MAX = Acnt;
            start = i - Ak + 1;
            end = i + Ak;
        } else {
            MAX = Bcnt;
            start = i - Bk + 1;
            end = i + Bk - 1;
        }
    }
    for (int i = start; i <= end; i++) {
        ans[j++] = s[i];
    }
    ans[j] = '\0';
    return ans;
}
