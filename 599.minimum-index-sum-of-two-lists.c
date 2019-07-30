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
    int k = 2000;
    *returnSize = 0;
    for (int i = 0; i < list1Size; i++) {
        for (int j = 0; j < list2Size; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (i + j < k) {
                    k = i + j;
                    *returnSize = 0;
                    ans[(*returnSize)++] = list1[i];
                } else if (i + j == k) {
                    ans[(*returnSize)++] = list1[i];
                }
            }
        }
    }
    return ans;
}
