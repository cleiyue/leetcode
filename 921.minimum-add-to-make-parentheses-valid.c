/*
 * @lc app=leetcode id=921 lang=c
 *
 * [921] Minimum Add to Make Parentheses Valid
 */


int minAddToMakeValid(char * S){
int len = strlen(S);
    int idx = 0;
    int *arr = malloc(len * sizeof(int));
    for (int i = 0; i < len; i++) {
        if (idx == 0) {
            arr[idx++] = S[i];
        } else {
            if (arr[idx - 1] == '(' && S[i] == ')') {
                idx--;
            } else {
                arr[idx++] = S[i];
            }
        }
    }
    return idx;
}



