/*
 * @lc app=leetcode id=412 lang=c
 *
 * [412] Fizz Buzz
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fizzBuzz(int n, int* returnSize) {
    char** ans = malloc(n * sizeof(char*));
    for (int i = 1; i <= n; i++) {
        if (i % 15 == 0) {
            ans[i - 1] = "FizzBuzz";
        } else if (i % 5 == 0) {
            ans[i - 1] = "Buzz";
        } else if (i % 3 == 0) {
            ans[i - 1] = "Fizz";
        } else {
            char buf[9];
            sprintf(buf, "%d", i);
            ans[i - 1] = malloc((strlen(buf) + 1) * sizeof(char));
            strcpy(ans[i - 1], buf);
        }
    }
    *returnSize = n;
    return ans;
}
