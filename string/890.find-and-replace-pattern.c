/*
 * @lc app=leetcode id=890 lang=c
 *
 * [890] Find and Replace Pattern
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool match(char* word, char* pattern) {
    int* map = calloc(26, sizeof(int));
    int* used = calloc(27, sizeof(int));
    int size = strlen(word);
    for (int i = 0; i < size; i++) {
        if (word[i] != pattern[i]) {
            if (map[word[i] - 'a'] == 0 && used[pattern[i] - 'a' + 1] == 0) {
                map[word[i] - 'a'] = pattern[i] - 'a' + 1;
                used[pattern[i] - 'a' + 1]++;
            }
            if (map[word[i] - 'a'] != pattern[i] - 'a' + 1) return false;
        } else {
            map[word[i] - 'a'] = pattern[i] - 'a' + 1;
            used[pattern[i] - 'a' + 1]++;
        }
    }
    return true;
}

char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize) {
    int** ans = malloc(sizeof(int*) * wordsSize);
    *returnSize = 0;
    for (int i = 0; i < wordsSize; i++) {
        if (match(words[i], pattern)) {
            ans[(*returnSize)++] = words[i];
        }
    }
    return ans;
}
