/*
 * @lc app=leetcode id=476 lang=c
 *
 * [476] Number Complement
 */

int findComplement(long num) {
    long i;
    for (i = 1; i <= num; i *= 2) num ^= i;
    return num;
}

int findComplement(int num) {
    unsigned mask = ~0;  // 11...10
    while (num & mask) mask <<= 1;
    return num ^ ~mask;
}
//
// num  00...0101
// mask 11...1000
//&两个位都为1，结果才为1
//^两个位相同为0，相异为1
//~0变1，1变0
