/*
 * @lc app=leetcode id=557 lang=c
 *
 * [557] Reverse Words in a String III
 */

char *reverseWords(char *s) {
    int len = strlen(s);
    char *ans = malloc((len + 1) * sizeof(char));
    int idx = 0;
    int a = 0;
    int b = 0;
    for (int i = 0; i <= len; i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            a = i;
            for (int j = a - 1; j >= b; j--) {
                ans[idx++] = s[j];
            }
            if (s[i] == ' ') {
                ans[idx++] = ' ';
                b = a + 1;
            }
        }
    }
    ans[idx] = '\0';
    return ans;
}
