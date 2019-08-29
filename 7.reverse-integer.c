/*
 * @lc app=leetcode id=7 lang=c
 *
 * [7] Reverse Integer
 */

int reverse(int x) {
    int max = 0x7fffffff, min = 0x80000000;
    long temp = 0;
    while (x != 0) {
        temp = temp * 10 + x % 10;
        x /= 10;
    }

    if (temp > max || temp < min) {
        return 0;
    } else {
        return (int)temp;
    }
}
