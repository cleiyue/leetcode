/*
 * @lc app=leetcode id=1021 lang=c
 *
 * [1021] Remove Outermost Parentheses
 */

char *removeOuterParentheses(char *S) {
    int len = strlen(S);
    char *ans = malloc((len - 1) * sizeof(char));
    int j = 0;
    int k = 1;
    for (int i = 1; i < len; i++) {
        if (S[i] == ')') {
            if (--k > 0) {
                ans[j++] = ')';
            }
        } else {
            if (++k > 1) {
                ans[j++] = '(';
            }
        }
    }
    ans[j] = '\0';
    return ans;
}
