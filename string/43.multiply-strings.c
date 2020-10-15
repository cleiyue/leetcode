/*
 * @lc app=leetcode id=43 lang=c
 *
 * [43] Multiply Strings
 */

char* multiply(char* num1, char* num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int anslen = len1 + len2 + 1;
    char* ans = calloc(anslen, sizeof(char));
    for (int i = 0; i < anslen; i++) {
        ans[i] = '0';
    }
    ans[anslen - 1] = '\0';
    for (int i = len1 - 1; i >= 0; i--) {
        for (int j = len2 - 1; j >= 0; j--) {
            int temp = ans[i + j + 1] - '0' + (num1[i] - '0') * (num2[j] - '0');
            ans[i + j + 1] = temp % 10 + '0';
            ans[i + j] = ans[i + j] - '0' + temp / 10 + '0';
        }
    }
    for (int i = 0; i < anslen; i++) {
        if (ans[i] - '0' > 0) {
            return ans + i;
        }
        if (i == anslen - 1) return "0";
    }
    return ans;
}
