/*
 * @lc app=leetcode id=509 lang=c
 *
 * [509] Fibonacci Number
 */

int fib(int N) {
    if (N <= 1) {
        return N;
    }
    int a = 0, b = 1, c = 0;
    while (N-- >= 2) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}
