/*
 * @lc app=leetcode id=409 lang=c
 *
 * [409] Longest Palindrome
 */

int longestPalindrome(char *s) {
    int *letters = calloc((26 + 6 + 26), sizeof(int));

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        letters[s[i] - 'A']++;
    }

    int ans = 0;
    for (int i = 0; i < 58; i++) {
        ans = ans + letters[i] - letters[i] % 2;
    }
    if (ans < len) {
        return ans + 1;
    } else {
        return ans;
    }
}
