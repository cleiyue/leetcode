/*
 * @lc app=leetcode id=1249 lang=c
 *
 * [1249] Minimum Remove to Make Valid Parentheses
 */

char * minRemoveToMakeValid(char * s){
    int len = strlen(s);
    int *right = malloc(sizeof(int)*len);
    int *left = malloc(sizeof(int)*len);
    int r = 0;
    int l = 0;
    for(int i=0; i<len; i++) {
        if(s[i] == '(') {
            right[r++] = i;
        } else if(s[i] == ')') {
            if(r > 0) {
                r--;
            } else {
                left[l++] = i;
            }
        }
    }
    
    int *hash = calloc(len, sizeof(int));
    for(int i=0; i < r; i++) {
        hash[right[i]] = 1;
    }
    
    for(int i=0; i < l; i++) {
        hash[left[i]] = 1;
    }
    
    char* ans = malloc(sizeof(char)*(len+1));
    int index = 0;
    
    for(int i=0; i<len; i++) {
        if(((s[i] == '(' || s[i] ==')') && hash[i] == 0) || s[i] > 64) {
            ans[index++] = s[i];
        } 
    }
    ans[index] = '\0';
    return ans;
}
