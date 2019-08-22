/*
 * @lc app=leetcode id=371 lang=c
 *
 * [371] Sum of Two Integers
 */

int getSum(int a, int b) {
    return b == 0 ? a : getSum(a ^ b, (a & b & 0xffffffff) << 1);
}
