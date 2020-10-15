/*
 * @lc app=leetcode id=9 lang=c
 *
 * [9] Palindrome Number
 * 
 * other solution: use array
 */

bool isPalindrome(int x) {
    if (x < 0 || x % 10 == 0 && x != 0) {
        return false;
    }
    int revertedNumber = 0;
    while (x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
    return x == revertedNumber || x == revertedNumber / 10;
}
