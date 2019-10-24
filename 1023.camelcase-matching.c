/*
 * @lc app=leetcode id=1023 lang=c
 *
 * [1023] Camelcase Matching
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool match(char* element, char* pattern) {
    int k = 0;
    int p_len = strlen(pattern);
    int e_len = strlen(element);
    for (int i = 0; i < e_len; i++) {
        if (k < p_len) {
            if (element[i] == pattern[k])
                k++;
            else if (element[i] < 'a' || element[i] > 'z')
                return false;
        } else {
            if (element[i] < 'a' || element[i] > 'z') return false;
        }
    }
    return k == p_len;
}

bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize) {
    bool* ans = malloc(sizeof(bool) * queriesSize);
    *returnSize = 0;
    for (int i = 0; i < queriesSize; i++) {
        char* element = queries[i];
        ans[(*returnSize)++] = match(element, pattern);
    }
    return ans;
}
