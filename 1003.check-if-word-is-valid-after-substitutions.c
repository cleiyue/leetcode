/*
 * @lc app=leetcode id=1003 lang=c
 *
 * [1003] Check If Word Is Valid After Substitutions
 */

bool isValid(char *S) {
    int idx = 0;
    int len = strlen(S);
    char *arr = malloc(len * sizeof(char));
    for (int i = 0; i < len; i++) {
        arr[idx++] = S[i];
        if (S[i] == 'c') {
            if (idx >= 3 && arr[idx - 2] == 'b' && arr[idx - 3] == 'a') {
                idx = idx - 3;
            }
        }
    }
    return idx == 0;
}
