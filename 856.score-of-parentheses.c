/*
 * @lc app=leetcode id=856 lang=c
 *
 * [856] Score of Parentheses
 */

#define MAX(a, b) (a > b ? a : b)
int scoreOfParentheses(char *S) {
    int idx = 0;
    int len = strlen(S);
    int *arr = malloc(len * sizeof(int));
    int ans = 0;
    arr[idx++] = 0;
    for (int i = 0; i < len; i++) {
        if (S[i] == '(') {
            arr[idx++] = 0;
        } else {
            int v = arr[idx - 1];
            int w = arr[idx - 2];
            idx = idx - 2;
            arr[idx++] = w + MAX(2 * v, 1);
        }
    }
    return arr[idx - 1];
}
