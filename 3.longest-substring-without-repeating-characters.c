/*
 * @lc app=leetcode id=3 lang=c
 *
 * [3] Longest Substring Without Repeating Characters
 */

#define MAX(a, b) (a > b ? a : b)
int lengthOfLongestSubstring(char *s) {
    int *letter = calloc(127, sizeof(int));
    int ln = strlen(s), ans = 0;
    for (int j = 0, i = 0; j < ln; j++) {
        i = MAX(letter[s[j]], i);
        ans = MAX(ans, j - i + 1);
        letter[s[j]] = j + 1;
    }
    return ans;
}