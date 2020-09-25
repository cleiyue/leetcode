/*
 * @lc app=leetcode id=67 lang=c
 *
 * [67] Add Binary
 */

// @lc code=start

char* addBinary(char* a, char* b) {
    int q = strlen(a);
    int w = strlen(b);
    int size = (q > w ? q : w) + 2;
    char* ans = malloc(size * sizeof(char));
    ans[size - 1] = '\0';
    for (int i = 0; i < q; i++) {
        ans[size - i - 2] = a[q - i - 1];
    }
    char t = 0;
    for (int i = 0; i < size - 1; i++) {
        int index = size - i - 2;
        // memset(ans,'0',size) too slow
        if (ans[index] != '0' && ans[index] != '1') {
            ans[index] = '0';
        }
        char r = ans[index] + t + (w - i - 1 >= 0 ? b[w - i - 1] : '0');

        if (r == '`') {
            ans[index] = '0';
            t = 0;
        } else if (r == 'a') {
            ans[index] = '1';
            t = 0;
        } else if (r == 'b') {
            ans[index] = '0';
            t = 1;
        } else {
            ans[index] = '1';
            t = 1;
        }
    }
    return ans[0] == '0' ? ans + 1 : ans;
}
// @lc code=end
