/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

#define MAX(a, b) (a > b ? a : b)
int lengthOfLongestSubstring(char *s) {
    char *letter = calloc(127, sizeof(char));
    int ln = strlen(s);
    int ans = 0, i = 0, j = 0;
    while (i < ln && j < ln) {
        if (letter[s[j]] == 0) {
            letter[s[j++]]++;
            ans = MAX(ans, j - i);
        } else {
            letter[s[i++]]--;
        }
    }
    return ans;
}