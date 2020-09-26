/*
 * @lc app=leetcode id=125 lang=c
 *
 * [125] Valid Palindrome
 */

// @lc code=start

bool isNum(char s) {
    return s >= '0' && s <= '9';
}

bool isLowercase(char s) {
    return s >= 'a' && s <= 'z';
}

bool isUppercase(char s) {
    return s >= 'A' && s <= 'Z';
}

bool isPalindrome(char* s) {
    int len = strlen(s);
    int i = 0, j = len - 1;
    while (i <= j) {
        char l = s[i];
        char r = s[j];
        if (isNum(l) || isLowercase(l) || isUppercase(l)) {
            if (isNum(r) || isLowercase(r) || isUppercase(r)) {
                if ((isNum(l) && isNum(r) && l == r) ||
                    (!isNum(l) && !isNum(r) && (l == r || l == r - 32 || l == r + 32))) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            } else {
                j--;
            }
        } else {
            i++;
        }
    }
    return i >= j;
}

// @lc code=end
