/*
 * @lc app=leetcode id=389 lang=c
 *
 * [389] Find the Difference
 */

char findTheDifference(char* s, char* t) {
    int lens = strlen(s);
    int lent = strlen(t);
    int ans = 0;
    for (int i = 0; i < lens; i++) {
        ans ^= s[i];
    }
    for (int i = 0; i < lent; i++) {
        ans ^= t[i];
    }
    return ans;
}
