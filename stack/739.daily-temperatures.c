/*
 * @lc app=leetcode id=739 lang=c
 *
 * [739] Daily Temperatures
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* T, int TSize, int* returnSize) {
    int MAX = 30000;
    int* ans = calloc(TSize, sizeof(int));
    int* range = malloc(101 * sizeof(int));
    for (int i = 0; i < 101; i++) {
        range[i] = MAX;
    }
    for (int i = TSize - 1; i >= 0; --i) {
        int warmerIndex = MAX;
        for (int j = T[i] + 1; j < 101; j++) {
            if (range[j] < warmerIndex) {  //找到最小index
                warmerIndex = range[j];
            }
        }
        if (warmerIndex < MAX) {
            ans[i] = warmerIndex - i;
        }
        range[T[i]] = i;
    }
    *returnSize = TSize;
    return ans;
}
