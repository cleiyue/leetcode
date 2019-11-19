/*
 * @lc app=leetcode id=1016 lang=c
 *
 * [1016] Binary String With Substrings Representing 1 To N
 */

char* int2bits(int n) {
    int len = (int)(log(n) / log(2)) + 1;
    char* bits = malloc(sizeof(char) * (len + 1));
    int index = len - 1;
    while (n > 0) {
        bits[index--] = n % 2 + '0';
        n = n / 2;
    }
    bits[len] = '\0';
    return bits;
}

bool queryString(char* S, int N) {
    for (int i = 1; i <= N; i++) {
        char* s = int2bits(i);
        if (!strstr(S, s)) return false;
    }
    return true;
}
