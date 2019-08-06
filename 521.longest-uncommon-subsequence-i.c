/*
 * @lc app=leetcode id=521 lang=c
 *
 * [521] Longest Uncommon Subsequence I 
 */
//给两个字符串，最长子序列是其中一个字符串的子序列而不是另一个字符串的子序列，字符串本身是字符串的子序列
#define MAX(a, b) (a > b ? a : b)
int findLUSlength(char* a, char* b) {
    return (strcmp(a, b) == 0 ? -1 : MAX(strlen(a), strlen(b)));
}
