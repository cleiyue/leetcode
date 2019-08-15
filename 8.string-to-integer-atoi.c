/*
 * @lc app=leetcode id=8 lang=c
 *
 * [8] String to Integer (atoi)
 */

int myAtoi(char* str) {
    int k = 0, sign = 1;
    int length = strlen(str);
    long i = 0;
    if (str[0] == ' ' || '-' || '+') {
        while (str[k] == ' ') {
            k++;
        }
        if (str[k] == '-') {
            sign = -1;
            k++;
        } else if (str[k] == '+') {
            sign = 1;
            k++;
        }
    }
    for (int j = k; j < length; j++) {
        if (isdigit(str[j])) {
            i = i * 10 + (str[j] - '0');
            if (i > INT_MAX) {
                if (sign == 1) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }
            }
        } else {
            break;
        }
    };
    return i * sign;
};
