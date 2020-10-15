/*
 * @lc app=leetcode id=728 lang=c
 *
 * [728] Self Dividing Numbers
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    int* ans = malloc((right - left) * sizeof(int));
    *returnSize = 0;
    for (int i = left; i <= right; i++) {
        if (i % 10 == 0) {
            continue;
        }
        if (i <= 9) {
            ans[(*returnSize)++] = i;
        } else if (i < 100) {  //10-99
            int a = i / 10;
            int b = i - a * 10;
            if (i % a == 0 && i % b == 0) {
                ans[(*returnSize)++] = i;
            }
        } else if (i < 1000) {
            int a = i / 100;
            int b = (i - a * 100) / 10;
            int c = i - a * 100 - b * 10;
            if (i % a == 0 && b != 0 && i % b == 0 && c != 0 && i % c == 0) {
                ans[(*returnSize)++] = i;
            }

        } else if (i < 10000) {
            int a = i / 1000;
            int b = (i - a * 1000) / 100;
            int c = (i - a * 1000 - b * 100) / 10;
            int d = i - a * 1000 - b * 100 - c * 10;
            if (b != 0 && c != 0 && d != 0 && i % a == 0 && i % b == 0 && i % c == 0 && i % d == 0) {
                ans[(*returnSize)++] = i;
            }
        }
    }
    return ans;
}
