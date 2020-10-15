/*
 * @lc app=leetcode id=917 lang=c
 *
 * [917] Reverse Only Letters
 */

int isLetter(char c) {
    if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)) {
        return 1;
    }
    return -1;
}

char* reverseOnlyLetters(char* S) {
    int len = strlen(S);
    int i = 0, j = len - 1;
    while (i < j) {
        if (isLetter(S[i]) == 1 && isLetter(S[j]) == 1) {
            char temp = S[i];
            S[i] = S[j];
            S[j] = temp;
            i++;
            j--;
        } else if (isLetter(S[i]) < 1) {
            i++;
        } else {
            j--;
        }
    }
    return S;
}
