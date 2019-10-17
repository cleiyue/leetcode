/*
 * @lc app=leetcode id=791 lang=c
 *
 * [791] Custom Sort String
 */

char* customSortString(char* S, char* T) {
    int* t_arr = calloc(26, sizeof(int));
    int t_len = strlen(T);
    for (int i = 0; i < t_len; i++) {
        t_arr[T[i] - 'a']++;
    }
    char* ans = malloc(sizeof(char) * (t_len + 1));
    int a_size = 0;
    int s_len = strlen(S);
    for (int i = 0; i < s_len; i++) {
        int k = S[i];
        int len = t_arr[k - 'a'];
        for (int j = 0; j < len; j++) {
            ans[a_size++] = k;
        }
        t_arr[k - 'a'] = 0;
    }

    for (int i = 0; i < 26; i++) {
        int len = t_arr[i];
        for (int j = 0; j < len; j++) {
            ans[a_size++] = i + 'a';
        }
    }
    ans[a_size++] = '\0';
    return ans;
}
