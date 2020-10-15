/*
 * @lc app=leetcode id=205 lang=c
 *
 * [205] Isomorphic Strings
 */

bool isIsomorphic(char *s, char *t) {
    int *letters = calloc(128, sizeof(int));
    int *lettert = calloc(128, sizeof(int));
    int maxs = 0;
    int maxt = 0;
    int lens = strlen(s);
    for (int i = 0; i < lens; i++) {
        if (letters[s[i]] == 0) {
            maxs++;
            letters[s[i]] = maxs;
        }
        if (lettert[t[i]] == 0) {
            maxt++;
            lettert[t[i]] = maxt;
        }
        if (lettert[t[i]] != letters[s[i]]) {
            return false;
        }
    }
    return true;
}
