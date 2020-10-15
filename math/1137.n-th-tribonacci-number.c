/*
 * @lc app=leetcode id=1137 lang=c
 *
 * [1137] N-th Tribonacci Number
 */

int tribonacci(int n) {
    int t0 = 0, t1 = 1, t2 = 1, total = 0;
    if (n == 0) {
        return 0;
    }
    if (n < 3) {
        return 1;
    }
    while (n-- >= 3) {
        total = t0 + t1 + t2;
        t0 = t1;
        t1 = t2;
        t2 = total;
    }
    return total;
}
