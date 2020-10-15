/*
 * @lc app=leetcode id=242 lang=c
 *
 * [242] Valid Anagram
 */

bool isAnagram(char *s, char *t) {
    int *k = calloc(26, sizeof(int));
    int lens = strlen(s);
    int lent = strlen(t);
    for (int i = 0; i < lens; i++) {
        k[s[i] - 'a']++;
    }

    for (int i = 0; i < lent; i++) {
        k[t[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++) {
        if (k[i] > 0 || k[i] < 0) {
            return false;
        }
    }
    return true;
}
