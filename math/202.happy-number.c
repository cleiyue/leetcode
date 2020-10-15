/*
 * @lc app=leetcode id=202 lang=c
 *
 * [202] Happy Number
 */

bool isHappy(int n) {
    if (n == 1) {
        return true;
    }
    if (n == 4) {
        return false;
    }
    int k = 0;
    while (n > 0) {
        k += (n % 10) * (n % 10);
        n /= 10;
    }
    return isHappy(k);
}
