/*
 * @lc app=leetcode id=482 lang=c
 *
 * [482] License Key Formatting
 */

// @lc code=start

char* licenseKeyFormatting(char* S, int K) {
    int sLen = strlen(S);
    int len = 0;
    for (int i = 0; i < sLen; i++) {
        if (S[i] != '-') len++;
    }
    if (len == 0) {
        char* ans = malloc(sizeof(char) * 1);
        ans[0] = '\0';
        return ans;
    }
    int fLen = len % K;
    int dashLen = len / K;
    if (fLen == 0) dashLen--;
    int ansLen = len + dashLen + 1;
    char* ans = malloc(sizeof(char) * ansLen);
    ans[--ansLen] = '\0';
    int temp = 0;
    for (int i = sLen - 1; i >= 0; i--) {
        if (S[i] != '-') {
            ans[--ansLen] = S[i] >= 97 ? S[i] - 32 : S[i];
            temp++;
            if (temp == K && ansLen > 0) {
                temp = 0;
                ans[--ansLen] = '-';
            }
        }
    }
    return ans;
}
// @lc code=end
