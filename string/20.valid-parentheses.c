/*
 * @lc app=leetcode id=20 lang=c
 *
 * [20] Valid Parentheses
 */

bool isValid(char *s) {
    int len = strlen(s);
    int idx = 0;
    int *arr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if (idx == 0) {
            arr[idx++] = s[i];
        } else {
            if ((arr[idx - 1] == '(' && s[i] == ')') ||
                (arr[idx - 1] == '[' && s[i] == ']') ||
                (arr[idx - 1] == '{' && s[i] == '}')) {
                idx--;
            } else {
                arr[idx++] = s[i];
            }
        }
    }
    return idx == 0;
}
