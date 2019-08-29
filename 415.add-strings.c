/*
 * @lc app=leetcode id=415 lang=c
 *
 * [415] Add Strings
 */

#define MAX(a, b) (a > b ? a : b)
char *addStrings(char *num1, char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    if (len1 == 0) return num2;
    if (len2 == 0) return num1;
    int anslen = MAX(len1, len2) + 2;
    char *ans = malloc(sizeof(char) * anslen);
    ans[--anslen] = '\0';
    int carry = 0;
    while (len1 >= 0 && len2 >= 0) {
        if (len1 == 0 && len2 == 0) break;
        int c1 = 0;
        if (len1 > 0) {
            c1 = num1[len1 - 1] - '0';
            len1--;
        }
        int c2 = 0;
        if (len2 > 0) {
            c2 = num2[len2 - 1] - '0';
            len2--;
        }
        int temp = carry + c1 + c2;
        if (temp > 9) {
            ans[--anslen] = temp % 10 + '0';
            carry = 1;
        } else {
            ans[--anslen] = temp + '0';
            carry = 0;
        }
    }
    if (carry == 1) {
        ans[--anslen] = '1';
        return ans;
    }
    return ans + 1;
}
