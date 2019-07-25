/*
 * @lc app=leetcode id=709 lang=c
 *
 * [709] To Lower Case
 */

char* toLowerCase(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (65 <= str[i] && str[i] <= 90) {
            str[i] = str[i] + 6 + 26;
        }
    }
    return str;
}
