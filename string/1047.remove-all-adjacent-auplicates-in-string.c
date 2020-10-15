/*
 * @lc app=leetcode id=1047 lang=c
 *
 * [1047] Remove All Adjacent Duplicates In String
 */

char * removeDuplicates(char * S){
    int i = 0;
    int len = strlen(S);
    char *ans = calloc(len+1, sizeof(char));
    for(int k = 0; k < len; k++) {
        if(i == 0) {
            ans[i++] = S[k];
        } else if(ans[i - 1] == S[k]){
            i--;
        } else {
            ans[i++] = S[k];
        }
    }
    ans[i]='\0';
    return ans;
}
