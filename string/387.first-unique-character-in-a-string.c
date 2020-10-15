/*
 * @lc app=leetcode id=387 lang=c
 *
 * [387] First Unique Character in a String
 */

int firstUniqChar(char *s) {
    int *k = calloc(26, sizeof(int));
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        k[s[i] - 'a']++;
    }

    for (int i = 0; i < len; i++) {
        if (k[s[i] - 'a'] == 1) {
            return i;
        }
    }
    return -1;
}
