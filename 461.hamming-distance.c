/*
 * @lc app=leetcode id=461 lang=c
 *
 * [461] Hamming Distance
 */

int hammingDistance(int x, int y) {
    int bit = x ^ y;  //相同为0， 相异为1
    int ans = 0;
    while (bit) {
        if ((bit >> 1) << 1 != bit) {  //计算1的数量
            ans++;
        }
        bit >>= 1;
    }
    return ans;
}
