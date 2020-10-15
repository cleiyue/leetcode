/*
 * @lc app=leetcode id=500 lang=c
 *
 * [500] Keyboard Row
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define lowcase(a) (90 >= a ? a + 32 : a)

char** findWords(char** words, int wordsSize, int* returnSize) {
    int* keybord = malloc(26 * sizeof(int));
    //row0
    keybord['q' - 'a'] = 0;
    keybord['w' - 'a'] = 0;
    keybord['e' - 'a'] = 0;
    keybord['r' - 'a'] = 0;
    keybord['t' - 'a'] = 0;
    keybord['y' - 'a'] = 0;
    keybord['u' - 'a'] = 0;
    keybord['i' - 'a'] = 0;
    keybord['o' - 'a'] = 0;
    keybord['p' - 'a'] = 0;
    //row1
    keybord['a' - 'a'] = 1;
    keybord['s' - 'a'] = 1;
    keybord['d' - 'a'] = 1;
    keybord['f' - 'a'] = 1;
    keybord['g' - 'a'] = 1;
    keybord['h' - 'a'] = 1;
    keybord['j' - 'a'] = 1;
    keybord['k' - 'a'] = 1;
    keybord['l' - 'a'] = 1;
    //row2
    keybord['z' - 'a'] = 2;
    keybord['x' - 'a'] = 2;
    keybord['c' - 'a'] = 2;
    keybord['v' - 'a'] = 2;
    keybord['b' - 'a'] = 2;
    keybord['n' - 'a'] = 2;
    keybord['m' - 'a'] = 2;

    char** ans = malloc(wordsSize * sizeof(char*));
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        char* word = words[i];
        int len = strlen(word);
        int start = keybord[lowcase(word[0]) - 'a'];
        bool k = true;
        for (int j = 0; j < len; j++) {
            if (start != keybord[lowcase(word[j]) - 'a']) {
                k = false;
                break;
            }
        }
        if (k) {
            ans[(*returnSize)++] = word;
        }
    }
    return ans;
}
