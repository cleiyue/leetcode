/*
 * @lc app=leetcode id=844 lang=c
 *
 * [844] Backspace String Compare
 */

bool backspaceCompare(char *S, char *T) {
    int lenS = strlen(S);
    int lenT = strlen(T);
    char *A = malloc((lenS + 1) * sizeof(char));
    char *B = malloc((lenT + 1) * sizeof(char));
    int k = 0;
    for (int i = 0; i < lenS; i++) {
        if (S[i] == '#') {
            k--;
            if (k < 0) {
                k = 0;
            }
        } else {
            A[k++] = S[i];
        }
    }
    A[k] = '\0';

    k = 0;
    for (int i = 0; i < lenT; i++) {
        if (T[i] == '#') {
            k--;
            if (k < 0) {
                k = 0;
            }
        } else {
            B[k++] = T[i];
        }
    }
    B[k] = '\0';
    return 0 == strcmp(A, B);
}
