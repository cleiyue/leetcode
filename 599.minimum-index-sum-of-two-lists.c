/*
 * @lc app=leetcode id=599 lang=c
 *
 * [599] Minimum Index Sum of Two Lists
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findRestaurant(char **list1, int list1Size, char **list2, int list2Size, int *returnSize) {
    char **ans = malloc(list1Size * sizeof(char *));
    int *index = malloc(list1Size * sizeof(int));
    int k = 2000;
    *returnSize = 0;
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                ans[*returnSize] = list1[i];
                index[*returnSize] = i + j;
                (*returnSize)++;
                if (i + j < k) {
                    k = i + j;
                }
            }
        }
    }
    int t = 0;
    for (int i = 0; i < *returnSize; i++) {
        if (index[i] == k) {
            ans[t++] = ans[i];
        }
    }
    *returnSize = t;
    return ans;
}
