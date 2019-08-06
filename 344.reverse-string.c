/*
 * @lc app=leetcode id=344 lang=c
 *
 * [344] Reverse String
 */

void reverseString(char* s, int sSize) {
    int i = 0, j = sSize - 1;
    for (; i <= j; i++, j--) {
        char k = s[i];
        s[i] = s[j];
        s[j] = k;
    }
}
