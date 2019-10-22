/*
 * @lc app=leetcode id=647 lang=c
 *
 * [647] Palindromic Substrings
 */

int countSubstrings(char* s) {
    int L = strlen(s);
    int ans = 0;
    for (int i = 0; i <= 2 * L - 1; ++i) {
        int left = i / 2;
        int right = left + i % 2;
        while (left >= 0 && right < L && s[left] == s[right]) {
            ans++;
            left--;
            right++;
        }
    }
    return ans;
}
