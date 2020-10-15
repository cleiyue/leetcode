/*
 * @lc app=leetcode id=231 lang=c
 *
 * [231] Power of Two
 */

bool isPowerOfTwo(int n) {
    return (n > 0) && !(n & (n - 1));
}
