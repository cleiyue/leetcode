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
        if (ans[size - i - 2] != '0' && ans[size - i - 2] != '1') {
            ans[size - i - 2] = '0';
        }
        char r = ans[size - i - 2] + t + (w - i - 1 >= 0 ? b[w - i - 1] : '0');
        t = 0;
        if (r == '`') {  //'0'+'0'
            ans[size - i - 2] = '0';
        } else if (r == 'a') {  //'1'+'0'
            ans[size - i - 2] = '1';
        } else if (r == 'b') {  // 'b' = '1'+'1'
            ans[size - i - 2] = '0';
            t = 1;
        } else {  // 'c' = '1'+'1'+'1'
            ans[size - i - 2] = '1';
            t = 1;
        }
    }
    if (ans[0] == '0') return ans + 1;
    return ans;
}
// @lc code=end
