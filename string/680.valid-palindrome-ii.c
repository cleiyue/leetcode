/*
 * @lc app=leetcode id=680 lang=c
 *
 * [680] Valid Palindrome II
 */

// @lc code=start

int judge(char *str, int i, int j) {
    while (i < j)
        if (str[i++] != str[j--]) return false;
    return true;
}

bool validPalindrome(char *s) {
    int len = strlen(s);
    int i = 0, j = len - 1;
    while (i <= j) {
        if (s[i] != s[j]) return judge(s, i + 1, j) || judge(s, i, j - 1);
        i++;
        j--;
    }
    return true;
}
// @lc code=end
