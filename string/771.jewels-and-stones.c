/*
 * @lc app=leetcode id=771 lang=c
 *
 * [771] Jewels and Stones
 */

int numJewelsInStones(char* J, char* S) {
    int Jlen = strlen(J);
    int Slen = strlen(S);
    int* hash = calloc(58, sizeof(int)); //58的原因是 Z~a 并不是连续的
    for (int i = 0; i < Slen; i++) {
        hash[S[i] - 'A']++;
    }
    int ans = 0;
    for (int i = 0; i < Jlen; i++) {
        ans += hash[J[i] - 'A'];
    }
    return ans;
}